/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:11:35 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/06 16:40:39 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "fdf.h"

t_map	*rotate_x(t_map *map, int dgr);
t_map	*rotate_y(t_map *map, int dgr);

#endif
