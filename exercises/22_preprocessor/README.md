# The Preprocessor

The C preprocessor is a tool that processes your source code before it is passed to the compiler. It handles directives that start with `#`, such as `#include`, `#define`, and conditional compilation directives like `#ifdef`.

## Conditional Compilation

Conditional compilation allows you to include or exclude parts of your code based on certain conditions, usually whether a macro is defined. This is useful for:
- Supporting multiple platforms (e.g., Windows vs. Linux)
- Enabling/disabling debug code
- Feature toggles

Common directives:
- `#ifdef MACRO`: Include code if `MACRO` is defined.
- `#ifndef MACRO`: Include code if `MACRO` is NOT defined.
- `#if expression`: Include code if the expression evaluates to non-zero.
- `#else`: Optional alternative if the condition is false.
- `#elif`: Optional "else if" condition.
- `#endif`: Required to close the conditional block.

## Include Guards

Include guards (or header guards) are a specific use of conditional compilation to prevent a header file from being included more than once in the same translation unit. This prevents "redefinition" errors for structs, enums, and other declarations.

A typical include guard looks like this:
```c
#ifndef HEADER_NAME_H
#define HEADER_NAME_H

// Declarations here...

#endif
```

## Exercise: ifdef

In this exercise, you need to use `#define` to enable a feature that is protected by an `#ifdef` block.

## Exercise: include_guards

In this exercise, you will encounter a compiler error because a header file is included multiple times. You need to add include guards to the header file to fix it.

## Related Concepts
- **21_macros**: Basic macro definitions using `#define`.
- **25_linkage**: Using headers to share declarations while keeping definitions in a single file.

## Further Reading
- [Beej's Guide: The Preprocessor](https://beej.us/guide/bgc/html/split/the-preprocessor.html)
- [Beej's Guide: Conditional Compilation](https://beej.us/guide/bgc/html/split/the-preprocessor.html#conditional-compilation)
- [Beej's Guide: Header Files](https://beej.us/guide/bgc/html/split/the-preprocessor.html#header-files)
