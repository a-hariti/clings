# String Literals

In C, a string literal is a sequence of characters enclosed in double quotes.

Example: `"Hello, world!"`

Technically, string literals are stored as an array of characters in a read-only section of memory. 
They are automatically null-terminated by the compiler, meaning a `\0` character is added to the end.

## Related Concepts
- **02_types**: String literals are technically arrays of `char`.
- **09_pointers**: String literals are often accessed via `char*`.

## Further Reading
- [Beej's Guide: Strings](https://beej.us/guide/bgc/html/split/strings.html#strings)
- [Beej's Guide: String Literals](https://beej.us/guide/bgc/html/split/strings.html#string-literals)
