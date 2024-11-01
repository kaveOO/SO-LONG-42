NAME		=	so_long

CC			=	clang
FLAGS		=	-Wall -Wextra -Werror

LIBFT_PATH	=	./LIBFT-42
MLX_PATH	=	./MLX-42

LIBFT_FILE	=	libft.a
MLX_FILE	=	libmlx.a

LIFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_FLAGS	=	-lX11 -lXext
MLX_EX		=	$(MLX_LIB) $(MLX_FLAGS)

C_FILES		=	main.c

SRC_DIR		=	./src/

