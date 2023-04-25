FROM debian:11-slim

WORKDIR /home/

RUN apt-get update && \
	apt-get install -y gcc-10make llvm clang-13 make valgrind

RUN apt-get clean

CMD ["bash"]
