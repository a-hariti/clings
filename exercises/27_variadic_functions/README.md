# Variadic Functions

Sometimes you don't know how many arguments a function will receive. C provides "variadic functions" to handle this, using the `stdarg.h` header. The most common variadic function you've likely used is `printf()`.

To define a variadic function, you use an ellipsis `...` as the last parameter. You must have at least one named parameter before the ellipsis.

Key macros from `stdarg.h`:
- `va_list`: A type to hold the information needed by the other macros.
- `va_start()`: Initializes the `va_list` to point to the first variadic argument.
- `va_arg()`: Retrieves the next argument of a specific type.
- `va_end()`: Cleans up the `va_list`.

## Exercise: sum

The goal of this exercise is to implement a function that sums an arbitrary number of integers.

## Related Concepts
- **10_functions**: Basics of function definitions and parameters.
- **26_function_pointers**: Advanced function handling.

## Further Reading
- [Beej's Guide: Variadic Functions](https://beej.us/guide/bgc/html/split/variadic-functions.html)
- `man 3 stdarg`
