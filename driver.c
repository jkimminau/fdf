/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:05:44 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/21 16:05:31 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		loop_events(t_mlx *mlx)
{
	mlx->color = color_increment(mlx->color, 4 + (mlx->party * 64));
	if (mlx->surge != 0)
	{
		mlx->ss = (mlx->ss > 1) ? 1 : mlx->ss;
		mlx->ss = (mlx->ss < 0) ? 0 : mlx->ss;
		if (mlx->surge <= 1)
			mlx->surge = mlx->map->maxz;
		else
			mlx->surge -= mlx->ss;
	}
	render(mlx);
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
			exit(0);
		}
		if (!(mlx->map = init_map(argv[1])))
		{
			ft_putendl("error reading map");
			exit(0);
		}
		mlx_key_hook(mlx->win, handle_keys, mlx);
		mlx_loop_hook(mlx->mlx, loop_events, mlx);
		mlx_loop(mlx->mlx);
		mlx_free(mlx, "");
	}
	return (0);
}
