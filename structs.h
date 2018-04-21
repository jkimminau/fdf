/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:50:32 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/17 10:08:28 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_point
{
	double			px;
	double			py;
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_map
{
	t_point			**map;
	double			wid;
	double			len;
	double			scale;
	double			zscale;
	double			maxz;
	int				x_view;
	int				y_view;
	double			x_off;
	double			y_off;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	t_map			*map;
	int				crosshairs;
	int				party;
	int				minimal;
	double			surge;
	double			ss;
	int				color;
}					t_mlx;

#endif
