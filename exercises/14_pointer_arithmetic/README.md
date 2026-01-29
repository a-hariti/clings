# Pointer Arithmetic

Pointers are not just memory addresses; they are also numbers that can be manipulated. When you add 1 to a pointer, it doesn't move 1 byte—it moves by the size of the type it points to.

This is extremely powerful for iterating through arrays without using index variables.

## Related Concepts
- **13_arrays**: Arrays and pointers are closely related in C; array names often decay to pointers.
- **15_string_manipulation**: Many string functions (like `strlen`) are implemented using pointer arithmetic.

## Further Reading
- [Beej's Guide: Pointer Arithmetic](https://beej.us/guide/bgc/html/split/pointers2.html#pointer-arithmetic)
