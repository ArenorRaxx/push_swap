# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorso <mcorso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:03:03 by mcorso            #+#    #+#              #
#    Updated: 2022/06/06 12:06:25 by mcorso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
HEAD			=	./

#	FILES
SRC_FILE		=	main.c \
					bruteforce_engine.c \
					move_manager.c \
					parsing.c \
					resolver.c \
					set_manager.c \
					stack_manager.c

OBJS			=	$(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))

#***INCLUDES
#***	PRINTF
		PRINTF	=	./includes/ft_printf/
	PRINTF_LIB	=	$(addprefix $(PRINTF), libftprintf.a)
	PRINTF_INC	=	-I $(PRINTF)
   PRINTF_LINK	=	-L$(PRINTF) -lftprintf
#***	LIBFT
		LIBFT	=	./includes/libft/
	LIBFT_LIB	=	$(addprefix $(LIBFT), libft.a)
	LIBFT_INC	=	-I $(LIBFT)
   LIBFT_LINK	=	-L$(LIBFT) -lft

#	COMPILER
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

#	DIR
SRC_DIR			=	./srcs/
OBJ_DIR			=	./objs/

#	RULES
all				:	obj $(PRINTF_LIB) $(LIBFT_LIB) $(NAME)

obj				:	
					mkdir -p $(OBJ_DIR)

$(PRINTF_LIB)	:
					make -C $(PRINTF)

$(LIBFT_LIB)	:
					make -C $(LIBFT)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
					$(CC) $(CFLAGS) $(PRINTF_INC) $(LIBFT_INC) -I$(HEAD) -o $@ -c $<

$(NAME)			:	$(OBJS)
					$(CC) -o $(NAME) $(OBJS) $(PRINTF_LINK) $(LIBFT_LINK)

clean			:
					rm -rf $(OBJ_DIR)
					make -C $(LIBFT) clean
					make -C $(PRINTF) clean

fclean			:	clean
					rm -rf $(NAME)
					make -C $(LIBFT) fclean
					make -C $(PRINTF) fclean

re				:	fclean all