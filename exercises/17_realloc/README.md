# realloc

The `realloc()` function changes the size of the memory block pointed to by its first argument to the size specified by its second argument.

The key thing to remember is that `realloc()` may move the memory block to a new address to find enough contiguous space. If it does:
1. It copies the old data to the new location.
2. It frees the old memory block.
3. It returns a pointer to the new memory block.

If you don't update your pointer with the return value of `realloc()`, you might be left with a dangling pointer to the old, freed memory.

## Flexible Array Members (FAMs)

C99 introduced Flexible Array Members, which allow a structure to end with an array of unspecified size. This is a common pattern for variable-length structures:

```c
struct MyList {
    int length;
    int items[]; // Flexible Array Member
};
```

When allocating such a struct, you must manually calculate the size to include the array elements:
`malloc(sizeof(struct MyList) + num_elements * sizeof(int))`.

FAMs provide better performance and memory locality than having a separate pointer to a heap-allocated array.

## Exercise: resize

The goal of this exercise is to correctly handle the return value of `realloc()`.

## Exercise: flexible_array

The goal of this exercise is to correctly allocate memory for a struct with a Flexible Array Member.

## Further Reading
- [Beej's Guide: realloc()](https://beej.us/guide/bgc/html/split/dynamic-memory-allocation.html#realloc)
- [Beej's Guide: Flexible Array Members](https://beej.us/guide/bgc/html/split/structs-ii-more-fun-with-structs.html#flexible-array-members)
- `man 3 realloc`
