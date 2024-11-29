# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albillie <albillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 21:25:18 by albillie          #+#    #+#              #
#    Updated: 2024/11/29 20:52:50 by albillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

CC 			= cc
RM			= rm -f

CFLAGS 		+= -Wall -Wextra -Werror -O3 -g
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/build/libmlx42.a

LIB			= libft/libft.a

SRC 		=	src/parser.c \
				src/render.c
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(LIB) $(CLINKS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all bonus clear clean fclean re
