#!/usr/bin/env python3
import json
import os
import select
import subprocess
import sys
import termios
import time
import tty

STATE_FILE = ".c-lings-state.txt"
CONFIG_FILE = "exercises.json"
_first_clear = True

ESC = "\033"
ESC_KEY = "\x1b"
ALT_SCREEN_ON = ESC + "[?1049h"
ALT_SCREEN_OFF = ESC + "[?1049l"
CURSOR_HIDE = ESC + "[?25l"
CURSOR_SHOW = ESC + "[?25h"
CLEAR_HOME = ESC + "[2J" + ESC + "[H"
SGR_RESET = ESC + "[0m"
SGR_BOLD = ESC + "[1m"
SGR_REVERSE = ESC + "[7m"
SGR_GREEN = ESC + "[32m"
SGR_BOLD_GREEN = ESC + "[1;32m"
SGR_BOLD_YELLOW = ESC + "[1;33m"
SGR_BOLD_RED = ESC + "[1;31m"
SGR_BOLD_BLACK = ESC + "[1;30m"


def enter_screen():
    if os.name == "nt":
        return
    # Switch to the alternate screen buffer and hide cursor.
    sys.stdout.write(ALT_SCREEN_ON + CURSOR_HIDE)
    sys.stdout.flush()


def exit_screen():
    if os.name == "nt":
        return
    # Restore cursor and return to the main screen buffer.
    sys.stdout.write(CURSOR_SHOW + ALT_SCREEN_OFF)
    sys.stdout.flush()


def load_config():
    with open(CONFIG_FILE, "r") as f:
        return json.load(f)


def load_state():
    if not os.path.exists(STATE_FILE):
        return set()
    with open(STATE_FILE, "r") as f:
        return {line.strip() for line in f if line.strip()}


def save_state(passed_exercises):
    with open(STATE_FILE, "w") as f:
        for ex in sorted(list(passed_exercises)):
            f.write(ex + "\n")


def get_char():
    fd = sys.stdin.fileno()
    old_settings = termios.tcgetattr(fd)
    try:
        tty.setraw(fd)
        ch = os.read(fd, 1).decode("latin1")
        if ch == ESC_KEY:
            # Read escape sequence (arrows, etc.). Some terminals send ESC O A/B.
            seq = ""
            deadline = time.monotonic() + 0.2
            while time.monotonic() < deadline:
                rlist, _, _ = select.select([fd], [], [], 0.01)
                if not rlist:
                    break
                seq += os.read(fd, 1).decode("latin1")
                if seq and (seq[-1].isalpha() or seq[-1] == "~"):
                    break
                if len(seq) >= 6:
                    break

            if not seq:
                return ESC_KEY  # Just Esc

            # Normalize common arrow sequences.
            if seq.startswith(("[", "O")) and seq.endswith("A"):
                return "k"  # Up
            if seq.startswith(("[", "O")) and seq.endswith("B"):
                return "j"  # Down

            return ESC_KEY + seq
    finally:
        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
    return ch


def clear_screen():
    if os.name == "nt":
        os.system("cls")
        return
    global _first_clear
    if _first_clear:
        _first_clear = False
        # On first clear, fully wipe the alternate buffer.
        sys.stdout.write(CLEAR_HOME)
        sys.stdout.flush()
        return
    sys.stdout.write(CLEAR_HOME)
    sys.stdout.flush()


def get_file_mtime(path):
    try:
        return os.path.getmtime(path)
    except OSError:
        return 0


def draw_progress_bar(total, completed):
    try:
        columns, _ = os.get_terminal_size()
    except OSError:
        columns = 80

    width = columns - 25
    if width < 10:
        width = 40

    filled = int(width * completed / total)
    bar = "#" * filled
    if filled < width:
        bar += ">" + "-" * (width - filled - 1)

    print(f"Progress: [{SGR_GREEN}{bar}{SGR_RESET}] {completed}/{total}")


def list_exercises(exercises, passed, current_index):
    selected = current_index
    # Calculate column width for names
    max_name_len = max(len(ex["name"]) for ex in exercises) + 2

    while True:
        clear_screen()
        total = len(exercises)
        completed = len(passed)
        draw_progress_bar(total, completed)
        print("\nExercises:")

        try:
            _, lines = os.get_terminal_size()
            list_height = lines - 10
        except OSError:
            list_height = 20

        start = max(0, selected - list_height // 2)
        end = min(total, start + list_height)
        if end == total:
            start = max(0, end - list_height)

        for i in range(start, end):
            ex = exercises[i]
            is_passed = ex["name"] in passed
            status = (
                f"{SGR_BOLD_GREEN}DONE   {SGR_RESET}"
                if is_passed
                else f"{SGR_BOLD_YELLOW}PENDING{SGR_RESET}"
            )

            # Format columns
            name_col = f"{ex['name']}".ljust(max_name_len)
            if i == selected:
                line = f"  {status} {SGR_REVERSE}{name_col} {ex['path']}{SGR_RESET}"
            else:
                line = f"  {status} {name_col} {ex['path']}"
            print(line)

        print(
            f"\n{SGR_BOLD}↓/j ↑/k home/g end/G{SGR_RESET} | "
            f"{SGR_BOLD}[Enter]{SGR_RESET} select | "
            f"{SGR_BOLD}q/Esc{SGR_RESET} quit list"
        )

        ch = get_char()
        if ch == ESC_KEY or ch == "q":
            return current_index

        if ch == "k" or ch == "j":
            if ch == "k":
                selected = max(0, selected - 1)
            elif ch == "j":
                selected = min(total - 1, selected + 1)
        elif ch == "g":
            selected = 0
        elif ch == "G":
            selected = total - 1
        elif ch in ["\r", "\n"]:
            return selected


def run_exercise_command(exercise):
    cmd = ["make", "run", "-s", "-B", f"EXERCISE={exercise['path']}"]
    exercise_cflags = exercise.get("cflags")
    if exercise_cflags:
        if isinstance(exercise_cflags, list):
            exercise_cflags = " ".join(exercise_cflags)
        cmd.append(f"EXERCISE_CFLAGS={exercise_cflags}")
    env = os.environ.copy()
    env.setdefault(
        "ASAN_OPTIONS",
        "abort_on_error=1:halt_on_error=1:detect_leaks=0:print_summary=1:verbosity=0",
    )
    env.setdefault(
        "UBSAN_OPTIONS",
        "halt_on_error=1:print_summary=1:verbosity=0",
    )
    result = subprocess.run(cmd, capture_output=True, text=True, env=env)
    return result


def get_watch_files(exercise_path):
    directory = os.path.dirname(exercise_path)
    base_name = os.path.splitext(os.path.basename(exercise_path))[0]

    files_to_watch = []
    if os.path.isdir(directory):
        for f in os.listdir(directory):
            if f.startswith(base_name):
                files_to_watch.append(os.path.join(directory, f))
    return files_to_watch if files_to_watch else [exercise_path]


def watch_exercise(exercise, exercises, passed):
    watch_files = get_watch_files(exercise["path"])
    last_mtimes = {f: get_file_mtime(f) for f in watch_files}

    while True:
        clear_screen()
        draw_progress_bar(len(exercises), len(passed))
        print(f"Current exercise: {SGR_BOLD}{exercise['path']}{SGR_RESET}")
        if len(watch_files) > 1:
            print(f"Watching: {', '.join(os.path.basename(f) for f in watch_files)}")
        print("")

        print(f"{SGR_BOLD}🔄 Compiling...{SGR_RESET}")
        result = run_exercise_command(exercise)

        if result.returncode == 0:
            print(f"{SGR_BOLD_GREEN}✅ PASSED{SGR_RESET}\n")
            print(f"{SGR_BOLD}OUTPUT:{SGR_RESET}")
            print(result.stdout)

            if exercise["name"] not in passed:
                passed.add(exercise["name"])
                save_state(passed)
                clear_screen()
                draw_progress_bar(len(exercises), len(passed))
                print(f"Current exercise: {SGR_BOLD}{exercise['path']}{SGR_RESET}\n")
                print(f"{SGR_BOLD_GREEN}✅ PASSED{SGR_RESET}\n")
                print(f"{SGR_BOLD}OUTPUT:{SGR_RESET}")
                print(result.stdout)

            print(
                f"\n{SGR_BOLD}[n]{SGR_RESET} next | "
                f"{SGR_BOLD}[l]{SGR_RESET} list | "
                f"{SGR_BOLD}[q]{SGR_RESET} quit"
            )
        else:
            if result.stdout:
                print(result.stdout)
            if result.stderr:
                print(result.stderr)
            print(f"\n{SGR_BOLD}[l]{SGR_RESET} list | {SGR_BOLD}[q]{SGR_RESET} quit")
            print(f"{SGR_BOLD_BLACK}(Watching for changes...){SGR_RESET}")

        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(fd)
            while True:
                rlist, _, _ = select.select([sys.stdin], [], [], 0.3)
                if rlist:
                    # In watch mode, we just need basic single chars
                    ch = sys.stdin.read(1)
                    if ch == "q":
                        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
                        sys.exit(0)
                    elif ch == "l":
                        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
                        return "list"
                    elif ch == "n" and result.returncode == 0:
                        termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
                        return "next"

                changed = False
                for f in watch_files:
                    current_mtime = get_file_mtime(f)
                    if current_mtime != last_mtimes[f]:
                        last_mtimes[f] = current_mtime
                        changed = True

                if changed:
                    termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
                    break
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)


def main():
    if not os.path.exists(CONFIG_FILE):
        print(f"Error: {CONFIG_FILE} not found.")
        return

    exercises = load_config()
    passed = load_state()

    current_idx = 0
    # stop at the first exercise that hasn't been passed yet
    for i, ex in enumerate(exercises):
        if ex["name"] not in passed:
            current_idx = i
            break

    while True:
        action = watch_exercise(exercises[current_idx], exercises, passed)

        if action == "next":
            # Find the next exercise that hasn't been passed yet
            next_found = False
            for i in range(current_idx + 1, len(exercises)):
                if exercises[i]["name"] not in passed:
                    current_idx = i
                    next_found = True
                    break

            if not next_found:
                clear_screen()
                draw_progress_bar(len(exercises), len(passed))
                print("\n🎉 All exercises completed! Congratulations! 🎉")
                print(f"\n{SGR_BOLD}Press q/Esc to quit{SGR_RESET}")
                # Keep the final screen visible until the user quits.
                while True:
                    ch = get_char()
                    if ch in ("q", ESC_KEY):
                        sys.exit(0)
        elif action == "list":
            current_idx = list_exercises(exercises, passed, current_idx)


if __name__ == "__main__":
    try:
        enter_screen()
        main()
    except KeyboardInterrupt:
        print("\nExiting.")
    finally:
        exit_screen()
