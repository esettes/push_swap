# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 17:00:44 by iostancu          #+#    #+#              #
#    Updated: 2023/05/02 20:17:26 by iostancu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	=\033[0;32m
WHITE	= \033[0;37m
BWHITE	= \033[1;37m
LGREEN	=\033[2;32m
LWHITE	= \033[2;37m

NAME	= push_swap

OS		=	$(shell uname -s)

SRCDIR	= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC	= $(addprefix $(SRCDIR), $(SRCNAMES))
OBJDIR	= ./src/obj/
OBJS	= $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

LIBFT	= ./inc/libft/libft.a
GNL	= ./inc/gnl/gnl.a
COMPS	= $(LIBFT) $(GNL)

HEADERS	= -I include -I ./inc/libft/inc/ -I ./inc/headers/ -I ./inc/gnl/inc/

CC	= clang
CFLAGS	= -g3 -fsanitize=address -Wall -Wextra -Werror # -Ofast -fno-omit-frame-pointer

ifeq ($(OS), Linux)
	VALGRIND = valgrind --tool=memcheck --leak-check=full --track-origins=yes -s
endif

all: obj $(COMPS) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@ $(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME):	$(OBJS)
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(COMPS)
	@echo "${LWHITE}$(NAME) ${LGREEN}✓$(RESET)\033[2;33m"
	@echo "${BWHITE}Compilation ${GREEN}[OK]$(RESET)\033[2;33m"

$(LIBFT):
	@$(MAKE) -C $(dir $(LIBFT))

$(GNL):
	@$(MAKE) -C $(dir $(GNL))

LD_DEBUG=all

n:
	@norminette ./src/*.c ./inc/headers/*.h ./inc/gnl/inc/*.h ./inc/gnl/src/*.c ./inc/libft/inc/*.h ./inc/libft/src/*.c ./inc/libft/bonus/*.c

dbgfiles:
	@rm -rf *.dSYM
	@rm -rf *.DS_Store
	@echo "${LWHITE}Clean debug files... ${LGREEN}✓$(RESET)\033[2;33m"

clean:	dbgfiles
	@echo "${LWHITE}Clean push swap... ${LGREEN}✓$(RESET)\033[2;33m"
	@rm -rf ${OBJDIR}*.o
	@echo "${LWHITE}Clean Libft... ${LGREEN}✓$(RESET)\033[2;33m"
	@$(MAKE) -C $(dir $(LIBFT)) clean

fclean: dbgfiles
	@rm -rf $(NAME)
	@echo "${LWHITE}Clean push swap... ${LGREEN}✓$(RESET)\033[2;33m"
	@rm -rf ${OBJDIR}*.o
	@echo "${LWHITE}Clean Libft... ${LGREEN}✓$(RESET)\033[2;33m"
	@$(MAKE) -C $(dir $(LIBFT)) fclean
	@echo "${LWHITE}Clean GNL... ${LGREEN}✓$(RESET)\033[2;33m"
	@$(MAKE) -C $(dir $(GNL)) fclean
	@echo "${BWHITE}Clean all ${GREEN}[OK]$(RESET)"
	@echo "\n"

re: fclean all

.PHONY: all fclean clean re
