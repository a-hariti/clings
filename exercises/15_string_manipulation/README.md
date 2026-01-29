# Strings

In C, strings are not a first-class data type. Instead, they are simply arrays of characters that end with a special "null terminator" character: `\0`.

This terminator tells functions like `printf` or `strlen` where the string ends. Without it, these functions will continue reading memory past the end of the array, leading to Undefined Behavior.

## Exercises
- `01_terminator.c`: Add the null terminator.
- `02_string_libs.c`: Use common `string.h` helpers.
- `03_strlen_vs_sizeof.c`: Pick the right length function.
- `04_strncpy_termination.c`: Ensure truncation still terminates.
- `05_strncat_remaining.c`: Append using remaining space.
- `06_memcmp_vs_strcmp.c`: Compare buffers vs strings.
- `07_strchr_strrchr.c`: Find first/last matches.

## Further Reading
- [Beej's Guide: Strings](https://beej.us/guide/bgc/html/split/strings.html#strings)
- `man 3 string`
