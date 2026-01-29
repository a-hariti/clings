# Pointers

Pointers are one of C's most powerful (and often confusing) features. A pointer is simply a variable that stores the memory address of another variable.

## Exercise: address_of

In this exercise, you'll learn how to assign the address of a variable to a pointer.

## Exercise: deref

In this exercise, you'll learn how to modify the value of a variable by dereferencing its pointer.

## Exercise: const_pointers

In this exercise, you'll learn the difference between `const int *` (pointer to constant) and `int *const` (constant pointer).

## Exercise: const_qualifiers

In this exercise, you'll apply `const` to pointer parameters to prevent accidental mutation.

## Further Reading
- [Beej's Guide: Pointers](https://beej.us/guide/bgc/html/split/pointers.html#pointers)

Key concepts:
- `&` (Address-of operator): Used to get the memory address of a variable.
- `*` (Dereference operator): Used to access the value stored at the address a pointer holds.
- Pointer types: A pointer's type (e.g., `int *`) tells the compiler what kind of data it points to.
