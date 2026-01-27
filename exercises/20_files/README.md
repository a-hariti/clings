# File I/O

In C, all file I/O is performed through a `FILE` stream, which is a pointer to a `FILE` structure defined in `<stdio.h>`.

## Opening and Closing Files

The `fopen()` function is used to open a file:
```c
FILE *fp = fopen("filename.txt", "r");
```
The second argument is the **mode**:
- `"r"`: Read (fails if file doesn't exist)
- `"w"`: Write (creates or truncates)
- `"a"`: Append (creates or appends)
- `"r+"`: Read/Write (fails if file doesn't exist)
- `"w+"`: Read/Write (creates or truncates)
- `"a+"`: Read/Write (creates or appends)

**Crucial**: Always check if `fopen()` returned `NULL`. If it did, the file could not be opened (due to permissions, it doesn't exist, etc.).

When finished, always close the file with `fclose(fp)`.

## Binary I/O

While text I/O (`fprintf`, `fscanf`, `fgets`) is human-readable, it involves overhead to convert data to and from strings. Binary I/O allows you to write the raw bytes of your data (like a struct or an array) directly to a file.

The `fwrite()` function writes data:
```c
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```

The `fread()` function reads data:
```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
```

Arguments:
1. `ptr`: Pointer to the data to write/read.
2. `size`: Size of each element (often `sizeof(...)`).
3. `nmemb`: Number of elements.
4. `stream`: The `FILE` pointer.

It's common to use the `"b"` flag in `fopen()` modes (e.g., `"rb"`, `"wb"`) to indicate binary mode. On many systems (like Linux/macOS) this has no effect, but on Windows it prevents the translation of newline characters.

## Further Reading
- [Beej's Guide to C Programming: File Input/Output](https://beej.us/guide/bgc/html/split/file-inputoutput.html)
- [Beej's Guide to C Programming: Binary I/O](https://beej.us/guide/bgc/html/split/file-inputoutput.html#binary-io-basics)
- `man 3 fwrite`
- `man 3 fread`
