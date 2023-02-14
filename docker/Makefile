BLUE	=\033[0;35m
GREEN	=\033[0;36m
YELLOW	=\033[0;33m

TARGET_SRC = /home/
APP_NAME = push_swap_app:latest
CONTAINER = push_swap
MOUNT_SRC = /home/settes/Desktop/workspace/cursus/push_swap/
DOCKER_PATH = Dockerfile

all:	run	exec

list:
	@echo "${BLUE}"
	docker ps -a
	@echo "${GREEN}"
	docker ps
	@echo "${YELLOW}"
	docker images

build:
	sudo docker build -f ${DOCKER_PATH} -t ${APP_NAME} .

run:
	sudo docker run -d --mount type=bind,source=${MOUNT_SRC},target=${TARGET_SRC} --name ${CONTAINER} ${APP_NAME}

delete:
	@echo "${BLUE}"
	docker rm -fv ${CONTAINER}
#	@echo "${GREEN}"
#	docker rm  ${CONTAINER}
	@echo "${YELLOW}"
	docker rmi  ${APP_NAME}

exec:
	sudo docker exec -it ${CONTAINER} bash

help:
	@echo "${BLUE}GENERAL COMMANDS:\033[2;37m"
	@echo "[make] builds main image, and run a container and execute it with bash"
	@echo "[build] builds image"
	@echo "[exec] execute container with bash"
	@echo "[list] shows images and all containers"
	@echo "[delete] stops running containers, deletes containers and images"