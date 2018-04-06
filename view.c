/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:11:37 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/05 19:20:31 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

t_map	*rotate_x(t_map *map, int dgr)
{
	int		i;
	int		j;


	map->x_offset += 45 * dgr;
	while (map->x_offset < 0)
		map->x_offset += 360;
	if (map->x_offset > 359)
		map->x_offset %= 360;
	printf("z offset = %f\n", (double)((map->x_offset - 180) /90));
	i = 0;
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			map->map[i][j].x = (WINDOW_WIDTH / 2) + 
								((((j * map->scale) + (WINDOW_WIDTH / 2) - ((map->width * map->scale) / 2)) 
								  - (WINDOW_WIDTH / 2))) + 
								((map->map[i][j].z));
			j++;
		}
		i++;
	}
	return (map);
}

t_map	*rotate_y(t_map *map, double dgr)
{
	int		i;
	int		j;

	(void)dgr;
	i = 0;
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			//map->map[i][j].x += (M_PI / 8) * ((map->length / 2) - j) * map->scale;
			map->map[i][j].y = (WINDOW_LENGTH / 2) + ((map->map[i][j].y - (WINDOW_LENGTH / 2)) / 2) - (map->map[i][j].z);
			j++;
		}
		i++;
	}
	return (map);
}

/*t_map	*changescale(t_map *map, int scale)
{
	
}*/
