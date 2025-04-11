#!/bin/bash
# Start MariaDB service
service mariadb start

# Wait for MariaDB to start
until mysqladmin ping --silent; do
    echo "Waiting for MariaDB to start..."
    sleep 1
done

# Create database and user if they don't exist
mysql -e "CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};"
mysql -e "CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
mysql -e "GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';"
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
mysql -e "FLUSH PRIVILEGES;"

# Restart MariaDB in safe mode for the container
mysqladmin -u root -p${MYSQL_ROOT_PASSWORD} shutdown
exec mysqld_safe
