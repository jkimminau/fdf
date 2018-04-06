/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:17:21 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/05 18:53:36 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	draw_line(t_mlx *mlx, t_point p1, t_point p2, t_map *map)
{
	t_point		d;
	t_point		l;
	double		inc;

	(void)map;
	d.x = (int)(p2.x) - (int)(p1.x);
	d.y = (int)(p2.y) - (int)(p1.y);
	d.z = (int)(p2.z) - (int)(p1.z);
	inc = (ft_abs(d.x) > ft_abs(d.y)) ? ft_abs(d.x) : ft_abs(d.y);
	l.x = (int)p1.x;
	l.y = (int)p1.y;
	l.z = (int)p1.z;
	while (((p2.x - l.x) * d.x) > 0 || ((p2.y - l.y) * d.y) > 0)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, l.x, l.y,
			map->colorlo + ((l.z / map->maxz) * (map->colorhi - map->colorlo)));
		//mlx_pixel_put(mlx->mlx, mlx->win, l.x, l.y, 0xFFFFFF);
		l.x += (d.x / inc);
		l.y += (d.y / inc);
		l.z += (d.z / inc);
	}
}

void	center_lines(t_mlx *mlx, t_map *map)
{
	t_point p1;
	t_point p2;
	t_point p3;
	t_point p4;
	int		color;

	color = map->colorhi;
	map->colorhi = 0xFF0000;
	p1.x = WINDOW_WIDTH / 2;
	p1.y = 0;
	p1.z = map->maxz;
	p2.x = WINDOW_WIDTH / 2;
	p2.y = WINDOW_LENGTH;
	p2.z = map->maxz;
	p3.x = 0;
	p3.y = WINDOW_LENGTH / 2;
	p3.z = map->maxz;
	p4.x = WINDOW_WIDTH;
	p4.y = WINDOW_LENGTH / 2;
	p4.z = map->maxz;
	draw_line(mlx, p1, p2, map);
	draw_line(mlx, p3, p4, map);
	map->colorhi = color;
}

void	draw_map(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->length)
	{
		j = 0;
		while (j < map->width - 1)
		{
			draw_line(mlx, map->map[i][j], map->map[i][j + 1], map);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < map->width)
	{
		i = 0;
		while (i < map->length - 1)
		{
			draw_line(mlx, map->map[i][j], map->map[i + 1][j], map);
			i++;
		}
		j++;
	}
}
