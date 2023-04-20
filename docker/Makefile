BLUE	=\033[0;35m
GREEN	=\033[0;36m
YELLOW	=\033[0;33m

APPNAME = push_swap_app:latest
CONTAINER = push_swap
DOCKER_PATH = ./build/Dockerfile

OS		=	$(shell uname -s)
MOUNT_SRC	= /Users/${USER}/Desktop/cursus/push_swap
COMP_CMD = docker-compose
COMPOSE = ./docker-compose.yml

all:	up	exec

list:
	@echo "${BLUE}> Compose running containers: --------------------------"
	@$(COMP_CMD) -f $(COMPOSE) ps -a
	@echo "${LILA}> Running containers: \t--------------------------------${END}"
	@docker ps -a
	@echo "${LILA}> Existing docker images: ------------------------------${END}"
	@docker images 
	
up:
	@$(COMP_CMD) -f $(COMPOSE) up -d

b:
	@docker build -f $(DOCKER_PATH) . -t $(APPNAME)

down:
	@echo "$(RED) If image is not deleted. Run [ make del ]"
	@${COMP_CMD} -f $(COMPOSE) down --rmi all

delete: down
	docker rm -fv $(CONTAINER)
	docker rmi -f $(DOCKER_PATH) $(APPNAME)
	
#Check why delete cause error 
del:
	docker rmi -f $(DOCKER_PATH) $(APPNAME)
	
prune:
	docker system prune

exec:
	@docker exec -it $(CONTAINER) /bin/sh -c bash

help:
	@echo ""
	@echo "${BLUE}GENERAL COMMANDS: \n \033[2;37m"
	@echo "\t[ list ] \tShows images and all containers with compose."
	@echo "\t[ make ] \tExecutes 'up' and 'exec'."
	@echo "\t[ up ] \t\tBuilds images and run containers."
	@echo "\t[ exec ] \tExecutes container with bash."
	@echo "\t[ delete ] \tStop and delete containers and images."
	@echo "\t[ build ] \tBuild the image."
	@echo ""
	@echo "\t[ prune ] \tRemove: \n \
\t\t\t- all stopped containers \n \
\t\t\t- all networks not used by at least one container\n \
\t\t\t- all dangling images\n \
\t\t\t- all dangling build cache\n"
	@echo ""
	@echo "\tA normal workflow would be: [ make b ] + [ make ] "
	@echo ""
	@echo "\tThen you can [ make list ] to se all existing images and containers and"
	@echo "\tto delete the images and containers related, execute [ make down ] "
