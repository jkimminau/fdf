NAME = fdf

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRC_C =	fdf.c	\
		draw.c	\
		key.c	\
		init.c	\
		parse.c	\
		view.c	\

SRC = $(addprefix src/, $(SRC_C))

HEADER_DIR =	.	\

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
LIBFTH = libft/libft.h
LIBFTLNK = -L libft/ -l ft

MLX = minilibx/libmlx.a
MLXH = minilibx/mlx.h
MLXLNK = -L minilibx/ -l mlx -framework OpenGL -framework AppKit

all : $(NAME)

$(LIBFT):
	@make -C libft/

$(MLX):
	make -C minilibx/

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC) -I .
	mv *.o src

$(NAME): $(LIBFT) $(OBJ) $(MLX)
	gcc $(OBJ) -o $(NAME) $(LIBFTLNK) $(MLXLNK)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@make clean -C minilibx/
	/bin/rm -f fdf

re: fclean all
