FROM debian:bullseye
RUN apt-get update && apt-get install nginx openssl -y
COPY ./conf/nginx.conf /etc/nginx/sites-available/default
RUN mkdir /workspace
WORKDIR /workspace
COPY ./tools/nginx.sh .
RUN chmod +x nginx.sh
CMD ["./nginx.sh"]
