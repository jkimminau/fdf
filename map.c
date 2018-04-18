/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:50:15 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/16 21:26:52 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map			*freemap(t_map **map, char *errmsg)
{
	int		i;

	ft_putendl(errmsg);
	i = 0;
	while (i < (*map)->len)
	{
		if ((*map)->map[i])
			free((*map)->map[i]);
		i++;
	}
	if ((*map)->map)
		free((*map)->map);
	if (*map)
		free(*map);
	return (0);
}

t_point			*newpoint(void)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		return (0);
	point->x = 0;
	point->y = 0;
	point->z = 0;
	return (point);
}

t_map			*newmap(char *filename)
{
	t_map	*new;
	int		fd;
	char	*line;

	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (0);
	new->scale = 60;
	new->zscale = 10;
	new->maxz = 0;
	new->len = 0;
	new->wid = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (new->wid != 0 && new->wid != ft_wordcount(line))
			return (freemap(&new, "file has inconsistent input"));
		new->wid = ft_wordcount(line);
		new->len++;
	}
	close(fd);
	new->x_view = 0;
	new->y_view = 0;
	new->x_off = WINDOW_WIDTH / 2;
	new->y_off = WINDOW_LENGTH / 2;
	return (new);
}

t_map			*readmap(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		j = -1;
		line = ft_nextword(line);
		while (++j < map->wid)
		{
			map->map[i][j].x = (j * map->scale) + map->x_off
				- ((map->wid - 1) * map->scale / 2);
			map->map[i][j].y = (i * map->scale) + map->y_off
				- ((map->len - 1) * map->scale / 2);
			map->map[i][j].z = atoi(line);
			map->maxz = (map->maxz > atoi(line)) ? map->maxz : atoi(line);
			line = ft_nextword(ft_nextspace(line));
		}
		i++;
	}
	close(fd);
	return (map);
}

t_map			*init_map(char *filename)
{
	t_map	*map;
	int		i;

	if (!(map = newmap(filename)))
		return (0);
	if (!(map->map = (t_point **)malloc(sizeof(t_point *) * map->len)))
		return (freemap(&map, "error mallocing map"));
	i = -1;
	while (++i < map->len)
		if (!(map->map[i] = (t_point *)malloc(sizeof(t_point) * map->wid)))
			return (freemap(&map, "error mallocing map"));
	map = readmap(filename, map);
	return (map);
}
