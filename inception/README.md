# Inception: A Dockerized WordPress Environment

## Project Overview

This project demonstrates the use of Docker and Docker Compose to set up a multi-container web application. The application is a WordPress site, served by an Nginx web server and backed by a MariaDB database. Each component of the stack runs in its own container, providing a modular and portable environment.

## Technology Stack

- **Docker:** A containerization platform that allows for the creation of lightweight, isolated environments.
- **Docker Compose:** A tool for defining and managing multi-container Docker applications.
- **Nginx:** A high-performance web server, reverse proxy, and load balancer. In this project, it serves the WordPress site and handles SSL/TLS termination.
- **MariaDB:** A community-developed, commercially supported fork of the MySQL relational database management system. It serves as the database for the WordPress installation.
- **WordPress:** A popular open-source content management system.

## How to Compile and Run

1. **Prerequisites:** Docker and Docker Compose must be installed on the host machine.
2. **Configuration:**
   - Create a `.env` file in the `srcs` directory. This file should define the environment variables required for the database and WordPress configuration (e.g., `MYSQL_ROOT_PASSWORD`, `MYSQL_USER`, `MYSQL_PASSWORD`, `MYSQL_DATABASE`).
   - Create the directories `${HOME}/data/mariadb` and `${HOME}/data/wordpress` on the host machine. These directories will be used for data persistence.
3. **Build and Run:** From the `inception` directory, run the `make` command. This will build the Docker images and start the containers as defined in the `docker-compose.yml` file.
4. **Access the Application:** The WordPress site will be available at `https://localhost` in a web browser.

## Technical Concepts Learned

This project provides a practical understanding of several DevOps and system administration concepts:

- **Containerization:** The project demonstrates the principles of containerization by isolating each service (Nginx, WordPress, MariaDB) in its own container.
- **Orchestration:** Docker Compose is used to orchestrate the multi-container application, managing the lifecycle of the containers, their networking, and their volumes.
- **Networking:** A custom bridge network is created to allow the containers to communicate with each other.
- **Data Persistence:** Docker volumes are used to persist the MariaDB and WordPress data on the host machine. This ensures that the data is not lost when the containers are stopped or removed.
- **Nginx as a Reverse Proxy:** Nginx is configured as a reverse proxy to forward requests to the WordPress container. It also handles SSL/TLS termination, providing secure communication with the client.
- **Database Management:** The project demonstrates how to set up and configure a MariaDB database for use with a web application.
