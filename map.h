/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:58:02 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/16 15:31:13 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "fdf.h"

t_point	*newpoint();
void	printmap(t_map *ptr);
t_map	*readmap(char *filename, t_map *map);
t_map	*init_map(char *filename);

#endif
