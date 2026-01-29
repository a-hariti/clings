# Dynamic Memory Allocation (malloc and free)

Sometimes you don't know how much memory you'll need until your program is running. For this, C provides functions to allocate memory on the **heap**.

Unlike stack memory (local variables), heap memory persists until you explicitly free it.

## Exercise: heap_alloc

In this exercise, you need to allocate memory on the heap for an integer, assign a value to it, and then free it.

## Further Reading
- [Beej's Guide: Manual Memory Management](https://beej.us/guide/bgc/html/split/manual-memory-allocation.html#manual-memory-allocation)
- `man 3 malloc`
- `man 3 free`

Key functions:
- `malloc(size_t size)`: Allocates `size` bytes and returns a pointer to them.
- `calloc(size_t count, size_t size)`: Allocates and zero-initializes an array.
- `free(void *ptr)`: Releases the memory previously allocated by `malloc`.

Always check if `malloc` returned `NULL`, which happens if the system is out of memory!
