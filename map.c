/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:50:15 by jkimmina          #+#    #+#             */
/*   Updated: 2018/04/05 18:43:19 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map			*freemap(t_map *map, char *errmsg)
{
	int		i;

	ft_putstr(errmsg);
	i = 0;
	while (i < map->length)
	{
		if (map->map[i])
			free(map->map[i]);
		i++;
	}
	if (map->map)
		free(map->map);
	if (map)
		free(map);
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
	new->length = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (new->width != 0 && new->width != ft_wordcount(line))
			return (freemap(new, "file has inconsistent input"));
		new->width = ft_wordcount(line);
		new->length++;
	}
	close(fd);
	new->maxz = 0;
	new->x_offset = 0;
	new->y_offset = 0;
	new->colorlo = 0xFFFFFF;
	new->colorhi = 0x00FF00;
	return (new);
}

/*void			printmap(t_map *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (i < ptr->length)
	{
		j = 0;
		while (j < ptr->width)
		{
			ft_putnbr(ptr->map[i][j].z);
			ft_putchar(',');
			j++;
		}
		ft_putendl("");
		i++;
	}

}*/

t_map			*readmap(char *filename)
{
	int		fd;
	char	*line;
	t_map	*map;
	int		i;
	int		j;

	if (!(map = newmap(filename)))
		return (0);
	if (!(map->map = (t_point **)malloc(sizeof(t_point *) * map->length)))
		return (freemap(map, "error mallocing map"));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(map->map[i] = (t_point *)malloc(sizeof(t_point) * map->width)))
			return (freemap(map, "error mallocing map"));
		j = 0;
		line = ft_nextword(line);
		while (j < map->width)
		{
			map->map[i][j].y = (i * map->scale) + (WINDOW_LENGTH / 2) - ((map->length * map->scale) / 2);
			map->map[i][j].x = (j * map->scale) + (WINDOW_WIDTH / 2) - ((map->width * map->scale) / 2);
			map->map[i][j].z = atoi(line);
			if (map->map[i][j].z > map->maxz)
				map->maxz = map->map[i][j].z;
			line = ft_nextspace(line);
			line = ft_nextword(line);
			j++;
		}
		i++;
	}
	close(fd);
	return (map);
}
