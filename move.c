/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 21:07:50 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/14 13:53:44 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

t_map	*move_x(t_map *map, int dir)
{
	printf("was: %f\n", map->x_off);
	map->x_off += dir * 100;
	printf("is: %f\n", map->x_off);
	return (map);
}

t_map	*move_y(t_map *map, int dir)
{
	map->y_off += dir * 10;
	return (map);
}
