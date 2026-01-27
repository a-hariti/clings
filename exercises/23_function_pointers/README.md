# Function Pointers

In C, functions are not just blocks of code; they also have an address in memory. You can store this address in a variable called a "function pointer". This allows you to pass functions as arguments to other functions, which is useful for implementing callbacks, sorting algorithms, and more.

The syntax for a function pointer can be a bit tricky:
```c
return_type (*pointer_name)(parameter_types);
```

## Exercise: callback

The goal of this exercise is to implement a `map` function that takes an array and a function pointer, and applies that function to each element of the array.

## Exercise: qsort

The `qsort` function in the standard library is a powerful tool for sorting any type of data. It uses a function pointer to know how to compare two elements of your custom data type.

Signature:
```c
void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));
```

## Exercise: void_pointer

`void*` is a generic pointer type that can point to any object. It's often used in conjunction with function pointers to create generic interfaces. Since `void*` cannot be dereferenced, you must cast it back to a concrete type before use.

## Further Reading
- [Beej's Guide: Function Pointers](https://beej.us/guide/bgc/html/split/pointers2.html#function-pointers)
- `man 3 qsort` (A classic example of a function that uses a function pointer)
