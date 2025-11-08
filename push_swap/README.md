# Push_swap: A Stack Sorting Algorithm

## Project Overview

This project is a C program that sorts a list of integers using a stack-based algorithm. The challenge is to sort the numbers in ascending order using a limited set of operations and with the fewest possible moves. The program is given a list of integers as command-line arguments and must output a sequence of operations that will sort the list.

## How to Compile and Run

1. **Compile:** The project includes a `Makefile`. Run the `make` command to build the `push_swap` executable.
2. **Run:** Execute the program with a list of integers as arguments.
   ```bash
   ./push_swap 5 2 8 1 9
   ```
   The program will output a sequence of operations that, when applied to the initial stack, will result in a sorted stack.

## Operations

The sorting algorithm is restricted to the following operations:

- `sa`: Swap the first two elements of stack A.
- `sb`: Swap the first two elements of stack B.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa`: Pop the top element from stack B and push it onto stack A.
- `pb`: Pop the top element from stack A and push it onto stack B.
- `ra`: Rotate stack A up by one position.
- `rb`: Rotate stack B up by one position.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra`: Rotate stack A down by one position.
- `rrb`: Rotate stack B down by one position.
- `rrr`: Perform `rra` and `rrb` simultaneously.

## Technical Concepts Learned

This project provides a practical understanding of several important computer science concepts:

- **Sorting Algorithms:** The project requires the design and implementation of a custom sorting algorithm that is optimized for the given constraints. The algorithm used is a variation of radix sort.
- **Stack Data Structure:** The project is a deep dive into the stack data structure and its operations.
- **Algorithmic Complexity and Optimization:** The primary goal of the project is to minimize the number of operations. This requires a focus on algorithmic complexity and optimization.
- **Problem Solving:** The project is a challenging puzzle that requires a good deal of problem-solving and algorithmic thinking.
- **Data Structures:** The project uses a linked list to implement the stack data structure.
