FROM debian:bullseye
RUN apt-get update && apt-get install -y mariadb-server mariadb-client
COPY ./conf/mariadb.cnf /etc/mysql/mariadb.conf.d/mariadb.cnf
COPY ./tools/mariadb.sh /usr/local/bin/mariadb.sh
RUN chmod +x /usr/local/bin/mariadb.sh
CMD ["sh", "-c", "/usr/local/bin/mariadb.sh"]
