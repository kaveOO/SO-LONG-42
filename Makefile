# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albillie <albillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 21:25:18 by albillie          #+#    #+#              #
#    Updated: 2024/12/05 07:31:12 by albillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

CC 			= cc
RM			= rm -f
CLONE		= git clone --depth=1

INCLUDE		= -I src/includes -I minilibx -I libft
CFLAGS 		= -Wall -Wextra -Werror -O3 -g $(INCLUDE)
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a

LIB			= libft
LIBFT		= $(LIB)/libft.a


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


$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(CLINKS)

$(MLX):
	$(CLONE) https://github.com/kodokaii/MLX42.git $(MLX)
	cmake $(MLX) -B $(MLX)

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(LIB):
	$(CLONE) https://github.com/kaveOO/LIB-PROJECTS.git $(LIB)

$(LIBFT): $(LIB)
	$(MAKE) -C $(LIB)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(MLX)
#	$(MAKE) clean -C $(LIB)


fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(MLX)
	$(RM) -r $(LIB)

re: fclean all

.PHONY:		all clean fclean re
