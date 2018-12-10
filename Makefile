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
OBJ = $(addprefix obj/, $(SRC_C:.c=.o))

HEADER_DIR =	.	\

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
	@make -C minilibx/

$(OBJ): $(SRC)
	@gcc $(CFLAGS) -c $(SRC) -I .
	@mkdir  -p obj
	@mv *.o obj

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@gcc $(OBJ) -o $(NAME) $(LIBFTLNK) $(MLXLNK)

clean:
	@/bin/rm -rf obj

fclean: clean
	@make fclean -C libft/
	@make clean -C minilibx/
	@/bin/rm -f fdf

re: fclean all
