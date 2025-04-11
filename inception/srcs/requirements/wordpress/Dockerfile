FROM debian:bullseye
RUN apt-get update && apt-get install -y php php7.4-fpm php-mysqli wget mariadb-client
RUN mkdir -p /var/www/html
WORKDIR /var/www/html
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/
COPY ./tools/wp.sh /wp.sh
RUN chmod +x /wp.sh
CMD ["/bin/bash", "/wp.sh"]
