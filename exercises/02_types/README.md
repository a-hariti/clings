# Types and Casting

C is a statically typed language. Every variable has a type that is determined at compile time. Sometimes you need to convert a value from one type to another, which is called "casting".

## Integer Division
One common pitfall in C is integer division. If you divide two integers, the result is always an integer, even if you assign it to a floating-point variable. The fractional part is simply discarded (truncated).

```c
float x = 5 / 2; // x will be 2.0, not 2.5
```

To get a floating-point result, at least one of the operands must be a floating-point type. You can achieve this by using a cast:

```c
float x = (float)5 / 2; // x will be 2.5
```

## Further Reading
- [Beej's Guide: Basic Types](https://beej.us/guide/bgc/html/split/variables-and-statements.html#basic-types)
- [Beej's Guide: Expressions and Operators](https://beej.us/guide/bgc/html/split/expressions.html)
