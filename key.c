/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:57:54 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/17 10:12:45 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int		handle_keys(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (key == 49)
		mlx->crosshairs = (mlx->crosshairs) ? 0 : 1;
	if (key == 35)
		mlx->party = (mlx->party) ? 0 : 1;
	if (key == 46)
		mlx->minimal = (mlx->minimal) ? 0 : 1;
	if (key == 45)
		mlx->surge = (mlx->surge != 0) ? 0 : 1;
	if (key == 11 || key == 9)
		mlx->ss += (key == 9) ? -0.25 : 0.25;
	if (key == 123 || key == 124)
		mlx->map = (key > 123) ? rotate_x(mlx->map, -1) : rotate_x(mlx->map, 1);
	if (key == 125 || key == 126)
		mlx->map = (key > 125) ? rotate_y(mlx->map, -1) : rotate_y(mlx->map, 1);
	if (key == 18 || key == 19)
		mlx->map->zscale += (key == 18) ? -1 : 1;
	return (0);
}
