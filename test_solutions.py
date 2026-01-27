#!/usr/bin/env python3
import json
import os
import subprocess
import sys

CONFIG_FILE = "exercises.json"

def load_config():
    with open(CONFIG_FILE, 'r') as f:
        return json.load(f)

def test_solutions():
    if not os.path.exists(CONFIG_FILE):
        print(f"Error: {CONFIG_FILE} not found.")
        return

    exercises = load_config()
    print(f"Testing {len(exercises)} solutions...\n")

    if not exercises:
        print("No exercises found.")
        return

    # Calculate padding for alignment
    # max_name_len = max_len + 1 (space) + 3 (dots)
    max_name_len = max(len(ex['name']) for ex in exercises) + 4

    failed = []

    for ex in exercises:
        # Construct solution path: exercises/x/y.c -> solutions/x/y.c
        # We assume the directory structure mirrors exactly.
        ex_path = ex['path']
        if ex_path.startswith("exercises/"):
            sol_path = "solutions/" + ex_path[len("exercises/"):]
        else:
            print(f"Skipping {ex['name']}: Path does not start with 'exercises/'")
            continue

        if not os.path.exists(sol_path):
             print(f"❌ {ex['name']}: Solution file not found at {sol_path}")
             failed.append(ex['name'])
             continue

        # Format: Name ..... Status
        # Pad name with spaces and dots
        print(f"{ex['name']} ".ljust(max_name_len, ".") + " ", end="", flush=True)

        # Run make with the solution file
        cmd = ["make", "run", "-B", f"EXERCISE={sol_path}"]

        # We capture output to keep the test run clean, unless it fails
        result = subprocess.run(cmd, capture_output=True, text=True)

        if result.returncode == 0:
            print("✅")
        else:
            print("❌")
            print("--- Output ---")
            print(result.stdout)
            print(result.stderr)
            print("--------------")
            failed.append(ex['name'])

    print("\n" + "="*30)
    if failed:
        print(f"❌ {len(failed)} tests failed.")
        sys.exit(1)
    else:
        print("🎉 All solutions verified successfully!")
        sys.exit(0)

if __name__ == "__main__":
    test_solutions()
