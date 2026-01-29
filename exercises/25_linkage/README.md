# Linkage

In C, "linkage" describes how a name can be seen by the linker. If a name has **external linkage**, it can be seen by other files (translation units) in your project. If it has **internal linkage**, it is private to the file where it is defined.

## Internal vs External Linkage

By default, global variables and functions have external linkage. You can give them internal linkage by using the `static` keyword at file scope.

```c
int global_var = 10;        // External linkage (visible to other files)
static int private_var = 5; // Internal linkage (private to this file)

void public_func(void);        // External linkage
static void private_func(void) { // Internal linkage
    // ...
}
```

One common error is a mismatch in linkage declarations. For example, if you declare a function as external (the default) and then define it as `static`, the compiler will complain because it doesn't know which linkage you actually want.

## External Variables (extern)

The `extern` keyword is used to declare a variable without defining it. It tells the compiler that the variable's storage is allocated elsewhere (in another file or later in the same file).

```c
extern int shared_data; // Declaration only, no memory allocated
```

This is essential for sharing global variables across multiple translation units.

## Persistence (Static Storage Duration)

The `static` keyword also has a completely different meaning when used inside a function. It specifies that a variable has **static storage duration**, meaning it is initialized only once and retains its value between function calls.

```c
void count(void) {
    static int c = 0; // Initialized once
    c++;
    printf("%d\n", c);
}
```

## Exercise: static_local

This exercise asks you to implement a counter using a static local variable.

## Further Reading

- [Beej's Guide to C Programming - Section 13.3: Linkage](https://beej.us/guide/bgc/html/split/multifile-projects.html#static-and-extern)
