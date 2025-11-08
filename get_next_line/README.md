# get_next_line: Reading a File Line by Line

## Project Overview

This project is a C function, `get_next_line`, that reads a file line by line. When called in a loop, it returns one line at a time from a given file descriptor. This project is a classic exercise in C programming that requires careful memory management, the use of static variables, and a good understanding of file I/O.

## How to Use It

To use `get_next_line` in your project, follow these steps:

1. **Include the header:** In your C source file, include the `get_next_line.h` header.
   ```c
   #include "get_next_line.h"
   ```
2. **Compile with your project:** When compiling your project, include the `get_next_line.c` and `get_next_line_utils.c` files.
   ```bash
   cc your_program.c get_next_line.c get_next_line_utils.c
   ```
3. **Usage in code:** The following example demonstrates how to use `get_next_line` to read a file line by line.
   ```c
   #include "get_next_line.h"
   #include <fcntl.h>
   #include <stdio.h>

   int main(void)
   {
       int     fd;
       char    *line;

       fd = open("your_file.txt", O_RDONLY);
       if (fd == -1)
       {
           perror("Error opening file");
           return (1);
       }
       while ((line = get_next_line(fd)))
       {
           printf("%s", line);
           free(line);
       }
       close(fd);
       return (0);
   }
   ```

## Technical Concepts Learned

This project provides a practical understanding of several important C programming concepts:

- **Static Variables:** The function uses a `static` variable to maintain the state of the buffer between calls to the function. This is a crucial aspect of the design, as it allows the function to remember its position in the file.
- **File I/O:** The project uses the `read` system call to read from a file descriptor. This provides a low-level understanding of how file I/O works in a Unix-like environment.
- **Dynamic Memory Management:** `get_next_line` uses `malloc` and `free` to manage memory for the lines it returns. This requires careful handling to avoid memory leaks.
- **Buffering:** To efficiently read from the file, the function uses a buffer. The `BUFFER_SIZE` macro determines the size of this buffer.
- **String Manipulation:** The project involves building the returned line by joining strings from the buffer and handling the newline character.
