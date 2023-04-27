FROM debian:11-slim

WORKDIR /home/

RUN apt-get update && \
	apt-get install -y make valgrind

RUN apt-get clean

CMD ["bash"]
