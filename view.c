/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:11:37 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/06 16:58:18 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

t_map	*rotate_x(t_map *map, int dgr)
{
	int		i;
	int		j;

	map->x_offset += 10 * dgr;
	while (map->x_offset < 0)
		map->x_offset += 360;
	if (map->x_offset > 359)
		map->x_offset %= 360;
	i = 0;
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			map->map[i][j].x = (WINDOW_WIDTH / 2) + 
								((((j * map->scale) + (WINDOW_WIDTH / 2) - ((map->width * map->scale) / 2)) - (WINDOW_WIDTH / 2)) * cos(M_PI / 180 * map->x_offset)) - 
								(map->map[i][j].z * sin(M_PI / 180 * map->x_offset) * 10);
			j++;
		}
		i++;
	}
	return (map);
}

t_map	*rotate_y(t_map *map, int dgr)
{
	int		i;
	int		j;

	map->y_offset += 10 * dgr;
	while (map->y_offset < 0)
		map->y_offset += 360;
	if (map->y_offset > 359)
		map->y_offset %= 360;
	i = 0;
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			map->map[i][j].y = (WINDOW_LENGTH / 2) + 
								((((i * map->scale) + (WINDOW_LENGTH / 2) - ((map->length * map->scale) / 2)) - (WINDOW_LENGTH / 2)) * cos(M_PI / 180 * map->y_offset)) + 
								(map->map[i][j].z * sin(M_PI / 180 * map->y_offset) * 10);
			j++;
		}
		i++;
	}
	return (map);
}

/*t_map	*changescale(t_map *map, int scale)
{
	
}*/
