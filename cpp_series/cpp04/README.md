# C++ Module 04: Polymorphism, Abstract Classes, and Interfaces

This module provides a deep dive into the concepts of polymorphism, abstract classes, and interfaces in C++. The exercises demonstrate how these concepts are used to create flexible and extensible object-oriented designs.

## Exercises

### Exercise 00: Polymorphism

This exercise introduces the concept of polymorphism. It demonstrates the difference between virtual and non-virtual functions and how they affect the behavior of derived classes.

- **Key Concepts:**
  - Inheritance
  - Polymorphism
  - Virtual functions
  - Base and derived classes

- **Compilation and Execution:**
  ```bash
  make -C ex00
  ./ex00/polymorphism
  ```

### Exercise 01: Deep vs. Shallow Copies

This exercise explores the difference between deep and shallow copies. It demonstrates how to implement a copy constructor and an assignment operator that perform a deep copy, which is essential when a class contains pointers to dynamically allocated memory.

- **Key Concepts:**
  - Deep copy vs. shallow copy
  - Copy constructor
  - Assignment operator
  - Dynamic memory allocation

- **Compilation and Execution:**
  ```bash
  make -C ex01
  ./ex01/copies
  ```

### Exercise 02: Abstract Classes and Interfaces

This exercise introduces the concept of abstract classes and interfaces. It demonstrates how to create an abstract base class with pure virtual functions to define an interface that derived classes must implement.

- **Key Concepts:**
  - Abstract classes
  - Pure virtual functions
  - Interfaces

- **Compilation and Execution:**
  ```bash
  make -C ex02
  ./ex02/abstract
  ```

## Compiling All Exercises

To compile all the exercises in this module, run the following command from the `cpp04` directory:
```bash
make
```
