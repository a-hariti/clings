# 09 Error Handling

Error handling in C usually relies on return codes, sentinel values, and
`errno`. This chapter emphasizes predictable control flow and clear diagnostics.

Topics:
- Guard clauses and early returns
- `errno` with `perror` / `strerror`
- Conventions for success/failure codes

Related chapters:
- **08_control_flow**: Branching patterns for handling errors.
- **23_files**: File APIs that report errors via return codes and `errno`.
