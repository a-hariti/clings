# Fixed Width Integers

In standard C, types like `int` and `long` have sizes that depend on the compiler and the architecture (e.g., a `long` might be 32 bits on Windows but 64 bits on Linux). This can lead to portability issues.

The `<stdint.h>` header provides **fixed-width integer types** that guarantee a specific size regardless of the platform.

Common types include:
- `int8_t`, `uint8_t`: 8-bit signed/unsigned integer
- `int16_t`, `uint16_t`: 16-bit signed/unsigned integer
- `int32_t`, `uint32_t`: 32-bit signed/unsigned integer
- `int64_t`, `uint64_t`: 64-bit signed/unsigned integer

## Related Concepts
- **02_types**: Basics of integer types and overflow.
- **23_files**: Binary file formats often rely on fixed-width types to ensure data is read correctly across different systems.

## Further Reading
- [Beej's Guide: Fixed Width Integer Types](https://beej.us/guide/bgc/html/split/fixed-width-integer-types.html#fixed-width-integer-types)
- `man stdint` (if available) or standard documentation.
