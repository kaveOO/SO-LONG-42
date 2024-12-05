# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albillie <albillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 21:25:18 by albillie          #+#    #+#              #
#    Updated: 2024/12/05 03:43:24 by albillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

CC 			= cc
RM			= rm -f

CFLAGS 		+= -I includes -Wall -Wextra -Werror -O3 -g
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/build/libmlx42.a

LIB			= libft/libft.a

SRC 		=	src/args/parser.c			\
				src/map/map.c				\
				src/map/parser.c			\
				src/map/parser1.c			\
				src/player/hooks.c			\
				src/player/player.c			\
				src/render/loader.c			\
				src/render/render.c			\
				src/utils/utils.c			\
				src/main.c					\

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
