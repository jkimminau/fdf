/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:11:37 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/16 21:51:49 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

t_map	*rotate_x(t_map *map, int dgr)
{
	map->x_view += 10 * dgr;
	while (map->x_view < 0)
		map->x_view += 360;
	if (map->x_view > 359)
		map->x_view %= 360;
	return (map);
}

t_map	*rotate_y(t_map *map, int dgr)
{
	map->y_view += 10 * dgr;
	while (map->y_view < 0)
		map->y_view += 360;
	if (map->y_view > 359)
		map->y_view %= 360;
	return (map);
}

int		color_increment(int color, int num)
{
	if (color % 0x000100 == 0xFF && color >> 8 < 0xFF)
		color += 0x000100;
	else if (color > 0xFF && color < 0x010000 && color % 0x000100 > 0)
		color -= 0x000001;
	else if ((color & 0xFF00) == 0xFF00 && color >> 16 < 0xFF)
		color += 0x010000;
	else if (color >> 16 == 0xFF && color >> 8 > 0xFF00)
		color -= 0x000100;
	else if (color >> 16 == 0xFF && color % 0x000100 < 0xFF)
		color += 0x000001;
	else
		color -= 0x010000;
	if (num <= 1)
		return (color);
	return (color_increment(color, num - 1));
}

t_map	*project(t_map *map)
{
	int		i;
	int		j;
	double	c;

	c = M_PI / 180;
	i = -1;
	while (++i < map->len)
	{
		j = -1;
		while (++j < map->wid)
		{
			map->map[i][j].px = map->x_off
				+ ((map->map[i][j].x - map->x_off) * cos(c * map->x_view))
				+ (map->map[i][j].z * -sin(c * map->x_view)
					* cos(c * map->y_view) * map->zscale)
				- ((map->len / 2 * map->scale) * sin(c * map->y_view)
					* sin(c * map->x_view)
					* ((((map->len - 1) / 2) - i) / ((map->len - 1) / 2)));
			map->map[i][j].py = map->y_off
				+ ((map->map[i][j].y - map->y_off) * cos(c * map->y_view))
				+ (map->map[i][j].z * sin(c * map->y_view) * map->zscale);
		}
	}
	return (map);
}

int		render(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->map = project(mlx->map);
	if (mlx->crosshairs)
		center_lines(mlx);
	draw_map(mlx);
	return (0);
}
