# Undefined Behavior

Undefined behavior (UB) occurs when your code violates the C language specification in a way that the standard does not define. In these cases, the compiler is not required to warn you, and the program's behavior becomes unpredictable—it might crash, produce wrong results, or appear to work "fine" until it doesn't.

One common source of UB is accessing memory that is no longer valid.

## Dangling Pointers

A dangling pointer is a pointer that points to a memory location that has been deallocated (or "gone out of scope"). 

A classic mistake is returning a pointer to a local variable from a function. Since local variables are stored on the **stack**, they are destroyed when the function returns. The pointer then points to "garbage" memory.

## Use After Free

Accessing memory through a pointer after that memory has been explicitly released with `free()` is another form of undefined behavior. Once memory is freed, the memory manager may reuse it for something else, so reading from or writing to it can corrupt data or cause crashes.

## Undefined Shifts

Shifting by a negative value or by an amount greater than or equal to the bit width is undefined behavior. Sanitizers can help catch these cases.

## Further Reading
- [Beej's Guide: Returning Pointers to Local Variables](https://beej.us/guide/bgc/html/split/pointers.html#returning-pointers-to-local-variables)
- [Beej's Guide: free()](https://beej.us/guide/bgc/html/split/malloc.html#freeing-memory)
- `man 3 free`
