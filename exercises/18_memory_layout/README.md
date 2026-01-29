# 18 Memory Layout

Understand how data is laid out in memory: alignment, padding, and offsets.
This chapter connects structs, arrays, and pointer arithmetic with the actual
layout chosen by the compiler.

Topics:
- Alignment and padding rules
- `offsetof` and field ordering
- Stack vs heap layout expectations

Exercises:
- `01_offsetof.c`: Measure field offsets.
- `02_padding_calc.c`: Calculate padding from offsets/sizes.
- `03_padding.c`: Reorder struct fields to shrink size.

Related chapters:
- **12_ptr_structs**: Structs and pointer access.
- **24_unions_bitfields**: Shared storage and bit-level representation.
