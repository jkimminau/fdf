/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 19:06:39 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/05 18:42:20 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_map
{
	t_point			**map;
	int				width;
	int				length;
	int				scale;
	int				maxz;
	int				colorlo;
	int				colorhi;
	int				x_offset;
	int				y_offset;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_map			*map;
	int				crosshairs;
}					t_mlx;

# define WINDOW_WIDTH	2000
# define WINDOW_LENGTH	1000
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "./X11_minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include "init.h"
# include "draw.h"
# include "map.h"
# include "view.h"

#endif
