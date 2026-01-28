# C-lings

Small C exercises to get you used to reading and writing C code, inspired by [Rustlings](https://github.com/rust-lang/rustlings) 🦀.

<p align="center">
    <img src="./assets/screenshot.png" alt="Screenshot" width="800">
</p>

## Recommended Resource

For a comprehensive and friendly guide to C, I recommend **[Beej's Guide to C Programming](https://beej.us/guide/bgc/)**.

It covers everything from basics to pointers and memory management in a very readable style.

## Setup

1. Clone this repo.

2. Make sure you have a C compiler installed (GCC or Clang).
   - On macOS/Linux, `cc` is usually available.
   - On Windows, you might need MinGW or WSL.

3. Run the runner:
   ```bash
   ./clings.py
   ```

## How to use

The script will guide you through the exercises in order.

1.  It will try to compile and run the current exercise.
2.  If it fails, read the error output.
3.  Open the file (e.g., `exercises/01_variables/variables1.c`) in your editor.

4.  Fix the code.
5.  The compiler will try to compile and run your code again.

Tips:

- You should open the termial in a vertical split for the fastest feedback loop.
- You can generally **Ctrl/Cmd + Click** to open the file in your editor.

## Progress

Your progress is saved in `.c-lings-state.txt`. To reset, just delete that file.

## License

MIT License.

## Related Projects

- [C-init](https://github.com/a-hariti/c-init): A tool to initialize a C project with everything you need to hit the ground running.
