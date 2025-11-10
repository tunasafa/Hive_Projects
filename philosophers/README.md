# Philosophers: A Dining Philosophers Simulation

## Project Overview

This project is a C implementation of the dining philosophers problem, a classic synchronization problem in computer science. The simulation involves a number of philosophers sitting at a round table, with a fork between each pair of philosophers. Each philosopher needs two forks to eat. The challenge is to design a solution that avoids deadlocks and starvation, ensuring that all philosophers get a chance to eat.

## How to Compile and Run

1. **Compile:** The project includes a `Makefile`. Run the `make` command to build the `philo` executable.
2. **Run:** Execute the program with the following command-line arguments:
   ```bash
   ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
   ```
   - `number_of_philosophers`: The number of philosophers at the table.
   - `time_to_die`: The time in milliseconds that a philosopher can go without eating before they die.
   - `time_to_eat`: The time in milliseconds that a philosopher spends eating.
   - `time_to_sleep`: The time in milliseconds that a philosopher spends sleeping.
   - `number_of_times_each_philosopher_must_eat` (optional): The simulation will stop after all philosophers have eaten this many times.

## Technical Concepts Learned

This project provides a practical understanding of several advanced C and systems programming concepts:

- **Multithreading:** The project uses the `pthread` library to create and manage a thread for each philosopher.
- **Mutexes:** The project uses mutexes to protect the shared resources (the forks). Each fork is a mutex, and a philosopher must lock the mutexes for both their left and right forks before they can eat.
- **Deadlocks:** The dining philosophers problem is a classic example of a deadlock-prone situation. This project requires a careful design to avoid deadlocks, such as by having philosophers pick up forks in a specific order.
- **Starvation:** The project also requires a solution that avoids starvation, where a philosopher is perpetually denied access to the resources they need.
- **Race Conditions:** The project demonstrates the importance of protecting shared data from race conditions by using mutexes.
- **Time Management:** The project uses the `gettimeofday` function to accurately measure time and to determine when a philosopher has died.
- **Synchronization:** The project is a comprehensive exercise in thread synchronization, requiring the careful coordination of multiple threads to achieve a correct and deadlock-free solution.
