# Control Flow

Control flow allows your program to make decisions and repeat actions. In C, this is primarily handled by `if`, `switch`, `while`, `do-while`, and `for` statements.

## Switch Fallthrough

One unique feature (and common source of bugs) in C is `switch` fallthrough. When a `case` matches, execution continues into subsequent `case` blocks unless a `break` statement is encountered.

## Loops

Loops (`for`, `while`, `do-while`) are used to execute a block of code multiple times. A common mistake is accidentally terminating a loop with a semicolon before the intended block.

## Further Reading
- [Beej's Guide: Control Flow](https://beej.us/guide/bgc/html/split/variables-and-statements.html#flow-control)
