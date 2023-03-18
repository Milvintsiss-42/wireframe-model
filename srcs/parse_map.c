/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:09:44 by ple-stra          #+#    #+#             */
/*   Updated: 2023/03/18 21:22:34 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_set_map_width(t_map *map, char **columns)
{
	char	**columns2;
	int		last_width;

	columns2 = columns;
	while (*columns)
		columns++;
	last_width = map->width;
	map->width = columns - columns2;
	if (map->width > last_width)
		map->width = last_width;
}

static t_map_elem	**ft_map_realloc(t_map *map, int height, int exactHeight)
{
	t_map_elem	**new_map;

	if (exactHeight)
		new_map = malloc(sizeof(t_map_elem *) * height);
	else
		new_map = malloc(sizeof(t_map_elem *) * (height + 10));
	if (!new_map)
	{
		ft_freemap(*map);
		return (0);
	}
	if (!map->map)
		return (new_map);
	if (!exactHeight)
		height--;
	while (height--)
		new_map[height] = map->map[height];
	free(map->map);
	return (new_map);
}

static void	ft_set_max_min_depth(t_fdf *fdf, int depth)
{
	if (depth > fdf->map.depth_max)
		fdf->map.depth_max = depth;
	if (depth < fdf->map.depth_min)
		fdf->map.depth_min = depth;
}

static void	ft_parse_columns(t_fdf *fdf, char *line)
{
	t_map	*map;
	char	**columns;
	int		i;

	map = &fdf->map;
	columns = ft_split(line, ' ');
	free(line);
	if (!columns)
		ft_exit(*fdf, ft_perror_errno(ERRNO_INSUFFICIENT_MEM) + 1);
	ft_set_map_width(map, columns);
	map->map[map->height - 1] = malloc(sizeof(t_map_elem) * map->width);
	if (!(map->map[map->height - 1]))
	{
		free(line);
		ft_freesplit(columns);
		ft_exit(*fdf, ft_perror_errno(ERRNO_INSUFFICIENT_MEM) + 1);
	}
	i = -1;
	while (++i < map->width)
	{
		map->map[map->height - 1][i] = ft_parse_point(columns[i]);
		ft_set_max_min_depth(fdf, map->map[map->height - 1][i].height);
	}
	ft_freesplit(columns);
}

void	ft_parse_map(t_fdf *fdf, int fd)
{
	t_map	*map;
	char	*line;

	map = &fdf->map;
	map->map = 0;
	map->height = 0;
	map->width = 2147483647;
	line = get_next_line(fd);
	while (line && *line)
	{
		map->height++;
		if (!map->map || map->height % 10 == 0)
			map->map = ft_map_realloc(map, map->height, 0);
		if (!map->map)
			ft_exit(*fdf, ft_perror_errno(ERRNO_INSUFFICIENT_MEM) + 1);
		ft_parse_columns(fdf, line);
		line = get_next_line(fd);
	}
	map->map = ft_map_realloc(map, map->height, 1);
	if (!map->map)
		ft_exit(*fdf, ft_perror_errno(ERRNO_INSUFFICIENT_MEM) + 1);
	if (map->height <= 0 || map->width <= 0)
		ft_exit(*fdf, ft_perror(ERR_INV_FILE) + 1);
	if (KDEBUG)
		ft_display_parsed_map(*map);
}
