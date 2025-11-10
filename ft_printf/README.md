# ft_printf: A Custom `printf` Implementation

## Project Overview

This project is a re-implementation of the standard C `printf` function. It's a foundational project that provides a deep understanding of variadic functions, formatted output, and low-level I/O. The goal is to create a function, `ft_printf`, that mimics the behavior of the original `printf`.

## How to Use It

To use `ft_printf` in your own projects, follow these steps:

1. **Compile the library:** The project includes a `Makefile` that compiles the source files into a static library, `libftprintf.a`. Run the `make` command to build it.
2. **Include the header:** In your C source files, include the `ft_printf.h` header file:
   ```c
   #include "ft_printf.h"
   ```
3. **Link the library:** When compiling your project, you'll need to link against the `libftprintf.a` library.
   ```bash
   cc your_program.c -L. -lftprintf
   ```
4. **Call the function:** You can now use `ft_printf` in your code just as you would use `printf`.
   ```c
   ft_printf("String: %s, Number: %d\n", "test", 123);
   ```

### Supported Format Specifiers

- `%c`: Print a single character.
- `%s`: Print a string.
- `%p`: Print a pointer address in hexadecimal format.
- `%d` or `%i`: Print a signed decimal integer.
- `%u`: Print an unsigned decimal integer.
- `%x`: Print an unsigned hexadecimal integer (lowercase).
- `%X`: Print an unsigned hexadecimal integer (uppercase).
- `%%`: Print a literal percent sign.

## Technical Concepts Learned

This project provides a comprehensive understanding of several key C programming concepts:

- **Variadic Functions:** The project is a practical application of variadic functions. It uses the `<stdarg.h>` header and the `va_list`, `va_start`, `va_arg`, and `va_end` macros to handle a variable number of arguments.
- **Formatted Output:** The core of the project is parsing the format string and handling the different format specifiers. This involves iterating through the format string, identifying the specifiers, and then calling the appropriate function to format and print the corresponding argument.
- **Static Libraries:** The project is structured as a static library, which is a common way to distribute and reuse code in C. This involves creating a `.a` file that can be linked into other programs.
- **Low-Level I/O:** Instead of using the standard I/O library, `ft_printf` uses the `write` system call to print characters to the standard output. This provides a better understanding of how I/O works at a lower level.
- **Number Base Conversion:** The project includes functions to convert integers to their hexadecimal and unsigned decimal representations.
