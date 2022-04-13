# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 08:26:22 by mbascuna          #+#    #+#              #
#    Updated: 2022/01/13 15:26:19 by mbascuna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
LIB_DIR		=	libft
HEADER		=	-I./pipex.h
SRCS	= ./pipex.c ./parsing.c ./main.c


OBJS	= ${SRCS:.c=.o}

RM		= rm -f

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

all:		${NAME}

.c.o:      
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ./pipex.h
			@echo "\033[35m----Compiling libft----"
			@make -C ${LIB_DIR}
			@${CC} ${FLAGS} ${HEADER} ${LIB_DIR}/libft.a ${OBJS} -o ${NAME}

%.o:		%.c libft/*.c
			@${CC} ${CFLAGS} -c $< -o $@

clean:
	@make clean -C ${LIB_DIR}
			${RM} ${OBJS}


fclean:		clean
			@make fclean -C ${LIB_DIR}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
