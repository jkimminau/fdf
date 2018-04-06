# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 19:11:37 by jkimmina          #+#    #+#              #
#    Updated: 2018/04/05 13:29:13 by jkimmina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	driver.c	\
		draw.c		\
		map.c		\
		init.c		\
		view.c

OBJ =	$(SRC:.c=.o)

HEADER = fdf.h		\
		 draw.h		\
		 map.h		\
		 init.h		\
		 view.h

HEADERDIR = .

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a
LIBFTLINK = -L./libft/ -lft

LIBMLX = ./minilibx/libmlx.a
LIBMLXLINK = -L./X11_minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

libmlx: $(LIBMLX)

$(LIBMLX):
	make -C ./X11_minilibx_macos/

$(NAME): $(LIBFT) $(LIBMLX)
	gcc $(FLAGS) -c $(SRC) -I$(HEADERDIR)
	gcc $(LIBRARY) $(OBJ) -o $(NAME) $(LIBFTLINK) $(LIBMLXLINK)

clean:
	/bin/rm -f $(OBJ) $(HEADER:.h=.h.gch)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/
	make clean -C X11_minilibx_macos/

re: fclean all
