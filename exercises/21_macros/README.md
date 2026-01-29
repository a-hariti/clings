# Macros

Macros are a powerful but dangerous feature of the C preprocessor. They perform simple text substitution before the compiler even sees the code. Because they are not functions, they don't have types and don't follow the same rules as regular C code.

## Exercise: syntax

The goal of this exercise is to fix the macro definition to handle operator precedence correctly.

## Exercise: side_effects

The goal of this exercise is to prevent double evaluation of arguments in a macro by using a safer alternative.

## Exercise: do_while

The goal of this exercise is to wrap multi-statement macros in `do { } while (0)` so they behave like a single statement.

## Exercise: stringify

The goal of this exercise is to implement a stringification macro that expands arguments before turning them into strings.

## Exercise: token_paste

The goal of this exercise is to build identifiers using `##`.

## Exercise: variadic_log

The goal of this exercise is to define a variadic macro that works with or without extra arguments.

## Further Reading
- [Beej's Guide: The Preprocessor](https://beej.us/guide/bgc/html/split/the-c-preprocessor.html#the-c-preprocessor)

Common pitfalls include:
- Operator precedence: Macros should almost always wrap their arguments and the entire expression in parentheses.
- Side effects: Arguments passed to a macro might be evaluated multiple times.
- Debugging: Macros can be hard to debug because the compiler only sees the result of the substitution.
