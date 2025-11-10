# Minitalk: A Signal-Based Communication System

## Project Overview

This project is a client-server communication system that uses Unix signals to transmit data. Instead of more common IPC mechanisms like sockets or pipes, `minitalk` sends messages one bit at a time, using two different signals (`SIGUSR1` and `SIGUSR2`) to represent 1s and 0s. This project provides a deep understanding of signal handling and low-level data transmission.

## How to Compile and Run

1. **Compile:** The project includes a `Makefile` that builds both the `client` and `server` executables. Run the `make` command.
2. **Run the server:**
   ```bash
   ./server
   ```
   The server will print its Process ID (PID).
3. **Run the client:** In a separate terminal, run the client with the server's PID and the string to be sent as arguments.
   ```bash
   ./client <SERVER_PID> "Your message here"
   ```
   The client will then transmit the string to the server, which will print it to the standard output.

## Technical Concepts Learned

This project provides a practical understanding of several advanced C and systems programming concepts:

- **Unix Signals:** The project is a deep dive into Unix signals. It uses the `signal` function to set up signal handlers, the `kill` function to send signals from the client to the server, and the `pause` function to make the server wait for signals.
- **Signal Handling:** The project demonstrates how to write a signal handler to receive and process signals. It also highlights the constraints of what can be done within a signal handler.
- **Bit Manipulation:** The core of the project is the transmission of data one bit at a time. This requires the use of bitwise operators (`<<` and `&`) to extract the individual bits of a character.
- **Client-Server Architecture:** The project is a simple implementation of a client-server model, where the server is a long-running process that waits for connections from clients.
- **Process IDs (PIDs):** The project uses PIDs to identify the server process. The `getpid` function is used to get the PID of the server.
- **Synchronization:** The `usleep` function is used in the client to introduce a small delay between signals. This helps to prevent signals from being missed by the server.
