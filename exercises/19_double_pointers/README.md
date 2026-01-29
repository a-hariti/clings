# Double Pointers

A double pointer (or pointer-to-pointer) is a variable that holds the address of another pointer.

```c
int x = 10;
int *p = &x;   // p points to x
int **pp = &p; // pp points to p
```

Double pointers are commonly used in C for:
1. **Modifying a pointer in another function**: If you want a function to change where a pointer in the caller's scope points (e.g., allocating memory), you must pass a pointer to that pointer.
2. **Dynamic 2D Arrays**: An array of pointers where each pointer points to an array of elements.
3. **Linked Lists/Trees**: Specifically when modifying the root or head pointer.

## Further Reading
- [Beej's Guide: Pointers II](https://beej.us/guide/bgc/html/split/pointers-iii-pointers-to-pointers-and-more.html#pointers-to-pointers)
