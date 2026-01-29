# Structs

Structs (short for structures) allow you to group multiple variables of different types under a single name. This is essential for creating complex data types.

When dealing with structs, you use the dot operator (`.`) to access members if you have the struct instance itself. If you have a pointer to a struct, you use the arrow operator (`->`).

## Struct Padding

The compiler often adds "padding" bytes between members of a struct to ensure that each member is correctly aligned in memory. This can sometimes make a struct larger than the sum of its parts. By reordering the members of a struct (usually from largest to smallest), you can often reduce its total size.

## Further Reading
- [Beej's Guide: Structs](https://beej.us/guide/bgc/html/split/structs.html)
- [The Lost Art of C Structure Packing](http://www.catb.org/esr/structure-packing/)
