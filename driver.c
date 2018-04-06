/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:05:44 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/06 16:58:17 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		handle_keys(int key, t_mlx *mlx)
{
	//printf("keycode = %d\n", key);
	if (key == 53)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (key == 49)
		mlx->crosshairs = (mlx->crosshairs) ? 0 : 1;
	if (key == 123)
		mlx->map = rotate_x(mlx->map, 1);
	if (key == 124)
		mlx->map = rotate_x(mlx->map, -1);
	if (key == 125)
		mlx->map = rotate_y(mlx->map, 1);
	if (key == 126)
		mlx->map = rotate_y(mlx->map, -1);
	printf("x_offset = %d\n", mlx->map->x_offset);
	printf("y_offset = %d\n", mlx->map->y_offset);
	mlx_clear_window(mlx->mlx, mlx->win);
	if (mlx->crosshairs)
		center_lines(mlx->mlx, mlx->map);
	draw_map(mlx->mlx, mlx->map);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc == 2)
	{
		if (!(mlx = initialize()))
		{
			ft_putendl("error initializing mlx");
			return (0);
		}
		if (!(mlx->map = readmap(argv[1])))
		{
			ft_putendl("error reading map");
			return (0);
		}
		mlx->map = rotate_x(mlx->map, -1);
		mlx->map = rotate_y(mlx->map, -1);
		draw_map(mlx, mlx->map);
		mlx_key_hook(mlx->win, handle_keys, mlx);
		mlx_loop(mlx->mlx);
		mlx_free(mlx, "");
	}
	return (0);
}
