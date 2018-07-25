FROM nginx:1.13

RUN mkdir -p /wwwroot/
ADD "files/vhosts/99-syncserver.conf" /etc/nginx/conf.d/default.conf

EXPOSE 80 443