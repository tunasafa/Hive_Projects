#!/bin/bash
# Install WP-CLI
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

# Set up directory permissions
mkdir -p /var/www/html
cd /var/www/html
rm -f index.nginx-debian.html

# Wait for MariaDB to be ready
echo "Waiting for MariaDB to be ready..."
until mysqladmin ping -h mariadb -u ${MYSQL_USER} -p${MYSQL_PASSWORD} --silent; do
    echo "MariaDB not ready yet... waiting 5 seconds"
    sleep 5
done
echo "MariaDB is ready!"

# Download WordPress if not already there
if [ ! -f "/var/www/html/wp-login.php" ]; then
    echo "Downloading WordPress..."
    wp core download --allow-root
fi

# Create wp-config.php if it doesn't exist
if [ ! -f "/var/www/html/wp-config.php" ]; then
    echo "Creating wp-config.php..."
    wp config create --allow-root --dbname=${MYSQL_DATABASE} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD} --dbhost=mariadb
fi

# Install WordPress if not already installed
echo "Installing WordPress..."
wp core install --allow-root --url=${WP_URL} --title="${WP_TITLE}" --admin_user=${WP_ADMIN_LOGIN} --admin_password=${WP_ADMIN_PASSWORD} --admin_email=${WP_ADMIN_EMAIL} || true
wp user create --allow-root ${WP_USER_LOGIN} ${WP_USER_EMAIL} --role=author --user_pass=${WP_USER_PASSWORD} || true

# Set correct permissions
chown -R www-data:www-data /var/www/html

# Start PHP-FPM
echo "Starting PHP-FPM..."
mkdir -p /run/php
php-fpm7.4 -F
