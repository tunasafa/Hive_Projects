# C++ Module 07: Templates

This module introduces the concept of templates in C++, which allow for writing generic, type-agnostic code. The exercises cover function templates and class templates.

## Exercises

### Exercise 00: Function Templates

This exercise demonstrates the use of function templates to create generic functions that can operate on different data types. The exercise implements `swap`, `min`, and `max` function templates.

- **Key Concepts:**
  - Function templates
  - Type deduction

- **Compilation and Execution:**
  ```bash
  make -C ex00
  ./ex00/whatever
  ```

### Exercise 01: Iter

This exercise demonstrates the use of a function template, `iter`, that takes an array, its length, and a function as arguments. The `iter` function applies the given function to each element of the array.

- **Key Concepts:**
  - Function templates
  - Function pointers

- **Compilation and Execution:**
  ```bash
  make -C ex01
  ./ex01/iter
  ```

### Exercise 02: Array

This exercise demonstrates the use of a class template to create a generic `Array` class. The `Array` class is a dynamic array that can hold elements of any type.

- **Key Concepts:**
  - Class templates
  - Dynamic memory allocation
  - Operator overloading (`[]`)
  - Exception handling

- **Compilation and Execution:**
  ```bash
  make -C ex02
  ./ex02/array
  ```

## Compiling All Exercises

To compile all the exercises in this module, run the following command from the `cpp07` directory:
```bash
make
```
