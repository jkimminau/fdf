/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:56:28 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/05 16:08:53 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_mlx	*mlx_free(t_mlx *mlx, char *errmsg)
{
	ft_putstr(errmsg);
	if (mlx->mlx)
		free(mlx->mlx);
	if (mlx->win)
		free(mlx->win);
	if (mlx)
		free(mlx);
	return (0);
}

t_mlx	*initialize(void)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	if (!(mlx->mlx = mlx_init()))
		return (mlx_free(mlx, "error initializing mlx pointer\n"));
	if (!(mlx->win = mlx_new_window(mlx->mlx,
					WINDOW_WIDTH, WINDOW_LENGTH, "fdf - 42")))
		return (mlx_free(mlx, "error initializing window pointer\n"));
	mlx->crosshairs = 0;
	return (mlx);
}
