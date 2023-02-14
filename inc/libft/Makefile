# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 17:01:06 by iostancu          #+#    #+#              #
#    Updated: 2023/02/13 17:28:03 by iostancu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	= \033[0;32m
BWHITE	= \033[1;37m
LGREEN	= \033[2;32m
LWHITE	= \033[2;37m
RESET	= \033[2;33m

SRCDIR	= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRCS	= $(addprefix $(SRCDIR), $(SRCNAMES))

OBJDIR	= ./obj/
OBJS	= $(addprefix $(OBJDIR), $(SRCNAMES:.c=.o))

B_SRCDIR	= ./bonus/
B_SRCNAMES	= $(shell ls $(B_SRCDIR) | grep -E ".+\.c")
B_SRCS	= $(addprefix $(B_SRCDIR), $(B_SRCNAMES))
OBJB	= $(addprefix $(OBJDIR), $(B_SRCNAMES:.c=.o))

NAME	= libft.a
BONUS	= .
CC  = clang#gcc
RM  = rm -f
CFLAGS  = -g3 -o0 -Wall -Wextra -Werror -I
AR = ar rc

LIBS	=  ./inc/

$(OBJDIR)%.o:$(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(LIBS) -o $@ -c $<

$(NAME):	$(OBJS) $(LIBS)
	@${AR} ${NAME} ${OBJS}
#	@ranlib ${NAME}
	@echo "${LWHITE}$(NAME) ${LGREEN}✓$(RESET)"


${BONUS}:	${OBJS} ${OBJB}
		@${AR}	${NAME} ${OBJB}
		@ranlib ${NAME}

bonus:	${BONUS}

all:	${NAME}

clean:
		@${RM} ${OBJS} ${OBJB}

fclean:	clean
		@${RM} ${NAME}

re:		fclean all bonus

.PHONY:	all clean fclean re
