/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:05:44 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/01 16:49:06 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		file;
	char	*line;
	void	*mlx;
	void	*win;

	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		while (get_next_line(file, &line) > 0)
			ft_putendl(line);
		close(file);
		mlx = mlx_init();
		if ((win = mlx_new_window(mlx, 100, 100, "mlx 42")) == 0)
			ft_putendl("error creating new window");
		mlx_key_hook(win, exit, 0);
		//mlx_loop(mlx);
		mlx_clear_window(mlx, win);
		mlx_destroy_window(mlx, win);
	}
	return (0);
}
