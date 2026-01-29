# Simple Structs

A `struct` (short for "structure") is a user-defined data type that allows you to group different variables under a single name. These variables, called members, can be of different types.

## Exercise: definition

The goal of this exercise is to define a simple struct and initialize it.

## Exercise: access

The goal of this exercise is to access and modify struct members using the dot operator.

Example:
```c
struct point {
    int x;
    int y;
};

struct point p = {10, 20};
```

## Related Concepts
- **07_enums_typedefs**: Typedefs are commonly used with structs to simplify declarations.
- **12_ptr_structs**: Advanced usage of structs with pointers and the arrow operator.

## Further Reading
- [Beej's Guide: Structs](https://beej.us/guide/bgc/html/split/structs.html#declaring-a-struct)
