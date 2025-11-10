# libft: A Custom C Library

## Project Overview

This project is a custom C library, `libft`, that contains a collection of re-implemented standard C library functions, as well as some additional utility functions. Creating a custom library is a foundational exercise for C programmers, as it provides a deep understanding of how these functions work under the hood and how to create reusable code modules.

## How to Use It

1. **Compile the library:** The project includes a `Makefile` that compiles the source files into a static library, `libft.a`. Run the `make` command to build it.
2. **Include the header:** In your C source files, include the `libft.h` header file:
   ```c
   #include "libft.h"
   ```
3. **Link the library:** When compiling your project, you'll need to link against the `libft.a` library.
   ```bash
   cc your_program.c -L. -lft
   ```

## Function Categories

The library includes a wide range of functions, which can be categorized as follows:

### Memory Manipulation

- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`

### String Manipulation

- `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`

### Character Classification and Conversion

- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`

### Type Conversion

- `ft_atoi`, `ft_itoa`

### File Descriptor Output

- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Linked List Manipulation (Bonus)

- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Technical Concepts Learned

This project provides a practical understanding of several fundamental C programming concepts:

- **Pointers and Memory Management:** A significant portion of the library is dedicated to functions that manipulate memory and strings, which requires a strong understanding of pointers and memory allocation.
- **Data Structures:** The bonus part of the project involves implementing a linked list, which is a fundamental data structure.
- **Static Libraries:** The project is structured as a static library (`.a` file), which is a common way to create reusable code modules in C.
- **Code Organization and Modularity:** The project is organized into multiple source files, each containing a related set of functions. This promotes code organization and modularity.
- **Testing and Debugging:** Writing a library of this nature requires thorough testing to ensure that the functions behave as expected in all edge cases.
