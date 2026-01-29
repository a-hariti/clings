# Phase 4: Functions

Functions are the blocks of code that perform a specific task. They allow you to encapsulate logic and reuse it.

## Function Prototypes

In C, the compiler reads the file from top to bottom. If you call a function before it has been defined, the compiler will complain (in modern C) or assume a default return type (in older C, which often leads to bugs).

To call a function that is defined later in the file or in another file, you must provide a **function prototype** (also called a forward declaration).

```c
// Prototype: tells the compiler about the function's signature
int add(int a, int b);

int main(void) {
    int x = add(5, 3); // Now the compiler knows 'add' exists
}

// Definition: the actual implementation
int add(int a, int b) {
    return a + b;
}
```

## Pass-by-Value

In C, arguments are passed to functions **by value**. This means the function receives a copy of the argument, not the original variable. Any changes made to the parameter inside the function do not affect the original variable in the caller.

```c
void attempt_increment(int x) {
    x = x + 1; // Only the copy is changed
}

int main(void) {
    int a = 5;
    attempt_increment(a);
    // a is still 5!
}
```

To modify the original variable, you must pass its **address** (a pointer). This is often called "pass-by-reference" in C context, although technically you are passing the pointer's value.

```c
void real_increment(int *x) {
    *x = *x + 1; // The value at the address is changed
}

int main(void) {
    int a = 5;
    real_increment(&a);
    // a is now 6!
}
```

## Further Reading
- [Beej's Guide to C Programming: Functions](https://beej.us/guide/bgc/html/split/functions.html#functions)
- [Beej's Guide to C Programming: Pointers (for Pass-by-Reference)](https://beej.us/guide/bgc/html/split/pointers.html#ptpass)
