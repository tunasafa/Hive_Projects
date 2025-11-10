# Minishell: A Custom Shell Implementation

## Project Overview

This project is a custom implementation of a command-line shell in C. It's a comprehensive project that covers a wide range of systems programming concepts, from parsing and executing commands to managing processes and handling signals. The goal is to create a shell that can interpret and execute a subset of the commands and features found in a standard shell like bash.

## How to Compile and Run

1. **Compile:** The project includes a `Makefile`. Run the `make` command to build the `minishell` executable.
2. **Run:** Execute the compiled binary:
   ```bash
   ./minishell
   ```
   This will start the shell and display the `Minishell:$` prompt.

## Features

- **Command History:** The shell uses the `readline` library to provide command history.
- **Built-in Commands:** The shell implements the following built-in commands: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Pipes:** The shell supports the use of pipes (`|`) to chain commands together.
- **I/O Redirection:** The shell supports input and output redirection (`<`, `>`, `<<`, `>>`).
- **Environment Variable Expansion:** The shell can expand environment variables (e.g., `$USER`).
- **Signal Handling:** The shell handles signals such as `Ctrl-C`, `Ctrl-D`, and `Ctrl-\`.

## Technical Concepts Learned

This project provides a practical understanding of several advanced C and systems programming concepts:

- **Parsing:** The shell parses the user's input into a command table, which is a structured representation of the commands to be executed. This involves lexical analysis and parsing.
- **Process Management:** The shell uses the `fork`, `execve`, and `waitpid` system calls to create and manage child processes for executing external commands.
- **File Descriptors and I/O Redirection:** The project requires a deep understanding of file descriptors to implement I/O redirection. The `dup2` system call is used to redirect the standard input, output, and error streams.
- **Pipes:** The shell uses the `pipe` system call to create pipes for inter-process communication between chained commands.
- **Signal Handling:** The project uses the `signal` and `sigaction` system calls to handle signals. This is crucial for making the shell robust and interactive.
- **Environment Variables:** The shell interacts with the environment variables of the operating system.
- **Built-in Commands:** The project demonstrates how to implement built-in commands, which are commands that are executed directly by the shell process itself, rather than in a child process.
- **Readline Library:** The `readline` library is used to provide a more user-friendly command-line interface with features like history and line editing.
