# Arrays

Arrays in C are a collection of elements of the same type stored in contiguous memory.

One of the most important concepts to understand is **Array Decay**. When an array is passed to a function, it "decays" into a pointer to its first element. This means that inside the function, you lose information about the array's size.

Another critical aspect is **Bounds Checking**. C does not perform bounds checking on arrays. Accessing an element outside the defined range (0 to length - 1) results in **Undefined Behavior**, which often leads to crashes or security vulnerabilities.

The bounds-checked exercise in this chapter has you implement a safe accessor that returns an error instead of reading out of bounds.

## Exercises
- `01_decay.c`: See array decay inside functions.
- `02_out_of_bounds.c`: Fix an off-by-one error.
- `03_bounds_checked.c`: Implement a safe accessor.
- `04_array_pointer_equiv.c`: Compare array and pointer expressions.
- `05_vla_params.c`: Pass a VLA with runtime sizes.

## Further Reading
- [Beej's Guide: Arrays](https://beej.us/guide/bgc/html/split/arrays.html#arrays)
- [Beej's Guide: Arrays and Pointers](https://beej.us/guide/bgc/html/split/arrays.html#arrays-and-pointers)
