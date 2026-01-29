# Enums and Typedefs

In C, you can define your own types to make your code more readable and easier to maintain.

## Enums
An `enum` (enumeration) is a custom type that allows you to assign names to integer constants. This makes your code more self-documenting.

```c
enum Day {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};
```

## Typedefs
The `typedef` keyword allows you to create an alias for an existing type. This is often used with structs to avoid having to write `struct` every time you declare a variable.

```c
typedef struct {
    int x;
    int y;
} Point;

Point p = {10, 20};
```

## Related Concepts
- **06_simple_structs**: Motivation for using `typedef` to avoid the `struct` keyword.
- **08_control_flow**: Using `enum` values in `switch` statements for state management.

## Further Reading
- [Beej's Guide: Enumerated Types: enum](https://beej.us/guide/bgc/html/split/enumerated-types-enum.html)
- [Beej's Guide: typedef: Making New Types](https://beej.us/guide/bgc/html/split/typedef-making-new-types.html)
