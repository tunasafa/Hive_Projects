# C++ Module 05: Exceptions, Interfaces, and Polymorphism

This module focuses on advanced C++ concepts such as exception handling, abstract classes, and polymorphism. The exercises build on each other to create a simulation of a bureaucracy, with bureaucrats, forms, and interns.

## Exercises

### Exercise 00: Bureaucrat

This exercise introduces the `Bureaucrat` class and the concept of exception handling. The `Bureaucrat` class has a grade that can be incremented or decremented, and it throws exceptions if the grade goes out of bounds.

- **Key Concepts:**
  - Exception handling (`try`, `catch`)
  - Custom exception classes

- **Compilation and Execution:**
  ```bash
  make -C ex00
  ./ex00/bureaucrat
  ```

### Exercise 01: Form

This exercise introduces the `Form` class, which can be signed by a `Bureaucrat`. The `Form` class also uses exceptions to handle cases where a `Bureaucrat`'s grade is not high enough to sign the form.

- **Key Concepts:**
  - Class interaction
  - More advanced exception handling

- **Compilation and Execution:**
  ```bash
  make -C ex01
  ./ex01/form
  ```

### Exercise 02: Abstract Form

This exercise refactors the `Form` class into an abstract base class, `AForm`, and creates three concrete form classes that inherit from it: `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`. This demonstrates the use of abstract classes and polymorphism.

- **Key Concepts:**
  - Abstract classes
  - Pure virtual functions
  - Polymorphism

- **Compilation and Execution:**
  ```bash
  make -C ex02
  ./ex02/abstract_form
  ```

### Exercise 03: Intern

This exercise introduces the `Intern` class, which can create different types of forms based on a string. This demonstrates the factory pattern.

- **Key Concepts:**
  - Factory pattern
  - Dynamic memory allocation

- **Compilation and Execution:**
  ```bash
  make -C ex03
  ./ex03/intern
  ```

## Compiling All Exercises

To compile all the exercises in this module, run the following command from the `cpp05` directory:
```bash
make
```
