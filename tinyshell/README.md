# Tinyshell: A Minimalist Shell

## Project Overview

This project is a single-file C program that implements a minimal command-line shell. Despite its small size, it supports command execution, pipes, and the built-in `cd` command. It's an excellent example of the power and conciseness of C for systems programming.

## How to Compile and Run

1. **Compile:**
   ```bash
   cc tinyshell.c -o tinyshell
   ```
2. **Run:** The shell is designed to be used by passing commands as arguments. For example:
   ```bash
   ./tinyshell /bin/ls -l | /usr/bin/grep tinyshell
   ```

## Technical Concepts Learned

This project provides a practical understanding of several key systems programming concepts:

- **Process Management:** The shell uses the `fork`, `execve`, and `waitpid` system calls to create and manage child processes for command execution.
- **Pipes:** The shell uses the `pipe` system call to create pipes for inter-process communication, allowing the output of one command to be used as the input for another.
- **File Descriptors:** The project demonstrates the use of `dup2` to manipulate file descriptors for redirecting I/O.
- **Built-in Commands:** The `cd` command is implemented as a built-in, which means it's handled directly by the shell process. This is necessary because a child process cannot change the working directory of its parent.
- **Error Handling:** The shell includes basic error handling and writes error messages to the standard error stream.
- **Recursive Execution:** The `main` function is structured to recursively execute commands separated by semicolons.
