# Strings

In C, strings are not a first-class data type. Instead, they are simply arrays of characters that end with a special "null terminator" character: `\0`.

This terminator tells functions like `printf` or `strlen` where the string ends. Without it, these functions will continue reading memory past the end of the array, leading to Undefined Behavior.

## Further Reading
- [Beej's Guide: Strings](https://beej.us/guide/bgc/html/split/strings.html)
- `man 3 string`
