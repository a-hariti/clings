# Arrays

Arrays in C are a collection of elements of the same type stored in contiguous memory.

One of the most important concepts to understand is **Array Decay**. When an array is passed to a function, it "decays" into a pointer to its first element. This means that inside the function, you lose information about the array's size.

Another critical aspect is **Bounds Checking**. C does not perform bounds checking on arrays. Accessing an element outside the defined range (0 to length - 1) results in **Undefined Behavior**, which often leads to crashes or security vulnerabilities.

The bounds-checked exercise in this chapter has you implement a safe accessor that returns an error instead of reading out of bounds.

## Further Reading
- [Beej's Guide: Arrays](https://beej.us/guide/bgc/html/split/arrays.html#arrays)
- [Beej's Guide: Arrays and Pointers](https://beej.us/guide/bgc/html/split/arrays.html#arrays-and-pointers)
