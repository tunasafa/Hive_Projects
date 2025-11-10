# C++ Module 00: Megaphone

## Project Overview

This project serves as a basic introduction to C++ programming. The `megaphone` program takes command-line arguments and outputs them in uppercase. This simple task provides an opportunity to explore fundamental concepts such as command-line argument processing, memory management, and basic I/O operations in C++.

## How to Compile and Run

To compile the project, navigate to the project directory and use the provided `Makefile`:
```bash
make
```

To run the program, execute the compiled binary with one or more strings as arguments:
```bash
./megaphone "This is a test."
```

The output will be the concatenated, uppercased version of the input strings:
```
THIS IS A TEST.
```

If no arguments are provided, the program outputs a specific message:
```
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

## Technical Concepts Learned

This project covers the following technical concepts:

- **Command-Line Arguments:** Understanding and utilizing `argc` (argument count) and `argv` (argument vector) to process input from the command line.
- **I/O Streams:** Using `std::cout` for writing to the standard output.
- **C-Style String Manipulation:** This project uses C-style strings (`char*`) and functions from `<cstring>` (`strlen`, `strcat`) and `<cctype>` (`toupper`) to manipulate character data.
- **Dynamic Memory Management:**  The program uses `new[]` to allocate memory for the concatenated input string and `delete[]` to free the allocated memory, demonstrating a fundamental aspect of C++ memory management.
- **Makefiles:** The use of a `Makefile` to automate the compilation process.
