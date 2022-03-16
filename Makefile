# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:03:03 by mcorso            #+#    #+#              #
#    Updated: 2022/03/16 13:20:40 by mcorso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

#	FILES
SRC_FILE		=	main.c

OBJS			=	$(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))

#	COMPILER
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

#	DIR
SRC_DIR			=	./srcs/
OBJ_DIR			=	./objs/
HEAD			=	./

all				:	obj $(NAME)

obj				:	
					mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					$(CC) $(CFLAGS) -I $(HEAD) -o $@ -c $<

$(NAME)			:	$(OBJS)
					$(CC) -o $(NAME) $(OBJS)

clean			:
					rm -rf $(OBJ_DIR)

fclean			:	clean
					rm -rf $(NAME)

re				:	fclean all