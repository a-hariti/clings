# Command Line Arguments

When you run a program from the command line, you can pass it arguments. In C, these are passed to the `main` function via two parameters: `argc` and `argv`.

- `argc` (argument count): An integer representing the number of arguments passed, including the program name itself.
- `argv` (argument vector): An array of strings (pointers to characters) containing the arguments. `argv[0]` is always the name of the program.

The signature of `main` for receiving arguments is:
```c
int main(int argc, char *argv[])
```

Or equivalently:
```c
int main(int argc, char **argv)
```

By convention, the array `argv` has `argc + 1` elements, and `argv[argc]` is always a null pointer.

## Exercise: argc_argv

The goal of this exercise is to change the `main` function signature to accept command line arguments and use them to pass the assertions.

## Related Concepts
- **16_double_pointers**: `argv` is an array of pointers (`char* argv[]`), which is effectively a `char**`.
- **13_string_manipulation**: Arguments are passed as strings and often need conversion (e.g., `atoi`).

## Further Reading
- [Beej's Guide: Command Line Arguments](https://beej.us/guide/bgc/html/split/the-outside-environment.html#command-line-arguments)
