all: start

start:
	@echo "🚀 Starting Inception..."
	@mkdir -p $(HOME)/data/wordpress
	@mkdir -p $(HOME)/data/mariadb
	@echo "127.0.0.1 stuna.42.fr" >> /etc/hosts
	@echo "127.0.0.1 www.stuna.42.fr" >> /etc/hosts
	@$(MAKE) build
	@$(MAKE) up
	@echo "✅ Inception is up and running!"

stop:
	@echo "🛑 Stopping Inception..."
	@$(MAKE) down
	@$(MAKE) prune
	@echo "✅ Cleanup complete!"

build:
	@docker-compose -f ./srcs/docker-compose.yml build

up:
	@docker-compose -f ./srcs/docker-compose.yml up -d

down:
	@docker-compose -f ./srcs/docker-compose.yml down

logs:
	@docker-compose -f ./srcs/docker-compose.yml logs

status:
	@docker ps

prune:
	@echo "🧹 Cleaning up data and system..."
	@sudo rm -rf srcs/data
	@docker system prune -f
	@rm -rf $(HOME)/data/wordpress
	@rm -rf $(HOME)/data/mariadb

rmi:
	@docker rmi srcs_wordpress srcs_mariadb srcs_nginx

re: stop start

.PHONY: all start stop build up down logs status prune rmi re
