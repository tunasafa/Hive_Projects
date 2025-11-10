# C++ Module 06: Type Casting

This module explores the different type casting mechanisms in C++. The exercises demonstrate the use of `static_cast`, `dynamic_cast`, and `reinterpret_cast`, and highlight the importance of choosing the correct cast for a given situation.

## Exercises

### Exercise 00: ScalarConverter

This exercise introduces the concept of a static class and demonstrates how to convert a string representation of a scalar value to its `char`, `int`, `float`, and `double` equivalents.

- **Key Concepts:**
  - `static_cast`
  - Static classes
  - Type conversion

- **Compilation and Execution:**
  ```bash
  make -C ex00
  ./ex00/convert <literal>
  ```

### Exercise 01: Serializer

This exercise demonstrates the use of `reinterpret_cast` to serialize and deserialize a pointer to a data structure. This is a powerful but dangerous cast that should be used with caution.

- **Key Concepts:**
  - `reinterpret_cast`
  - Serialization and deserialization
  - `uintptr_t`

- **Compilation and Execution:**
  ```bash
  make -C ex01
  ./ex01/serializer
  ```

### Exercise 02: Identify

This exercise demonstrates the use of `dynamic_cast` to identify the runtime type of an object. `dynamic_cast` is used to safely downcast a pointer or reference from a base class to a derived class.

- **Key Concepts:**
  - `dynamic_cast`
  - Runtime type identification (RTTI)
  - Polymorphism

- **Compilation and Execution:**
  ```bash
  make -C ex02
  ./ex02/identify
  ```

## Compiling All Exercises

To compile all the exercises in this module, run the following command from the `cpp06` directory:
```bash
make
```
