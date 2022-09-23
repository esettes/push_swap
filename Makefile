# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 17:00:44 by iostancu          #+#    #+#              #
#    Updated: 2022/09/21 17:00:45 by iostancu         ###   ########.fr        #
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
COMPS	= $(LIBFT)

HEADERS	= -I include -I ./inc/libft/inc/ -I ./inc/headers/

CC	= gcc
CFLAGS	= -O0 -g3  #-Ofast -fsanitize=leak -fno-omit-frame-pointer # -Wall -Wextra -Werror 

ifeq ($(OS), Linux)
	VALGRIND = valgrind --tool=memcheck --leak-check=full --track-origins=yes -s
endif

all: obj $(LIBFT) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@ $(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

#Change libx42_flags position at the end of the coommand
$(NAME):	$(OBJS)
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) 
	@echo "${LWHITE}$(NAME) ${LGREEN}✓$(RESET)\033[2;33m"
	@echo "${BWHITE}Compilation ${GREEN}[OK]$(RESET)\033[2;33m" 

$(LIBFT):
	@$(MAKE) -C $(dir $(LIBFT))

LD_DEBUG=all

dbgfiles:
	@rm -rf *.dSYM
	@rm -rf *.DS_Store
	@echo "${LWHITE}Clean debug files... ${LGREEN}✓$(RESET)\033[2;33m"

clean:	dbgfiles
	@echo "${LWHITE}Clean fdf... ${LGREEN}✓$(RESET)\033[2;33m"
	@rm -rf ${OBJDIR}*.o
	@echo "${LWHITE}Clean Libft... ${LGREEN}✓$(RESET)\033[2;33m"
	@$(MAKE) -C $(dir $(LIBFT)) clean

fclean: dbgfiles
	@rm -rf $(NAME)
	@echo "${LWHITE}Clean fdf... ${LGREEN}✓$(RESET)\033[2;33m"
	@rm -rf ${OBJDIR}*.o
	@echo "${LWHITE}Clean Libft... ${LGREEN}✓$(RESET)\033[2;33m"
	@$(MAKE) -C $(dir $(LIBFT)) fclean
	@echo "\n"

re: fclean all

.PHONY: all fclean clean re
