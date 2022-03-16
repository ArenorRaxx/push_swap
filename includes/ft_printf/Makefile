# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/25 12:06:45 by mcorso            #+#    #+#              #
#    Updated: 2022/03/16 16:38:57 by mcorso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD = ./

#	SRCS
SRC_DIR = ./srcs/
SRC_FILES = ft_printf.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putnbr_base.c\
		ft_putpointer_addr.c
SRCS = ${addprefix ${SRC_DIR}, ${SRC_FILES}}

#	OBJS
OBJ_DIR = ./obj/
OBJ_FILES = ${SRC_FILES:.c=.o}
OBJS = ${addprefix ${OBJ_DIR}, ${OBJ_FILES}}

#	NAME
NAME = libftprintf.a

#	PARAM
CC = gcc -Wall -Werror -Wextra
RM = rm -rf

all		:	obj $(NAME)

obj		:	
			mkdir -p $(OBJ_DIR)

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
		${CC} -I ${HEAD} -c $< -o $@
		
clean:
		${RM} ${OBJ_DIR}
		
fclean: clean
		${RM} ${NAME}
		
re:	fclean all

.PHONY: ${NAME} all re clean fclean
