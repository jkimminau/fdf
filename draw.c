/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 17:17:21 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/16 21:33:45 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int		getcolor(t_mlx *mlx, t_point l)
{
	if (mlx->party)
		return (color_increment(mlx->color, l.z + l.y + l.x));
	else if (mlx->minimal)
		return (mlx->color * l.z / mlx->map->maxz);
	else if (mlx->surge)
		return (mlx->color * (mlx->surge == (int)l.z));
	else
		return (color_increment(mlx->color, l.z * 10));
}

void	draw_line(t_mlx *mlx, t_point p1, t_point p2)
{
	t_point		d;
	t_point		l;
	double		inc;

	d.x = (p2.px - p1.px);
	d.y = (p2.py - p1.py);
	d.z = (p2.z - p1.z);
	inc = (fabs(d.x) > fabs(d.y)) ? fabs(d.x) : fabs(d.y);
	l.x = p1.px;
	l.y = p1.py;
	l.z = p1.z;
	while (fabs(p2.px - l.x) > 1 || fabs(p2.py - l.y) > 1)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, l.x, l.y,
				getcolor(mlx, l));
		l.x += (d.x / inc);
		l.y += (d.y / inc);
		l.z += (d.z / inc);
	}
}

void	center_lines(t_mlx *mlx)
{
	t_point p1;
	t_point p2;
	t_point p3;
	t_point p4;

	p1.px = WINDOW_WIDTH / 2;
	p1.py = 0;
	p1.z = 0;
	p2.px = WINDOW_WIDTH / 2;
	p2.py = WINDOW_LENGTH;
	p2.z = 0;
	p3.px = 0;
	p3.py = WINDOW_LENGTH / 2;
	p3.z = 0;
	p4.px = WINDOW_WIDTH;
	p4.py = WINDOW_LENGTH / 2;
	p4.z = 0;
	draw_line(mlx, p1, p2);
	draw_line(mlx, p3, p4);
}

void	draw_map(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mlx->map->len)
	{
		j = 0;
		while (j < mlx->map->wid - 1)
		{
			draw_line(mlx, mlx->map->map[i][j], mlx->map->map[i][j + 1]);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < mlx->map->wid)
	{
		i = 0;
		while (i < mlx->map->len - 1)
		{
			draw_line(mlx, mlx->map->map[i][j], mlx->map->map[i + 1][j]);
			i++;
		}
		j++;
	}
}
