/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:09:44 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/24 20:27:30 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_freesplit(char **split)
{
	char	**to_free;

	to_free = split;
	while (*split)
		free(*split++);
	free(to_free);
}

static int	ft_get_width(char **columns)
{
	char	**columns2;

	columns2 = columns;
	while (*columns)
		columns++;
	return (columns - columns2);
}

static int	**ft_realloc(t_map *map, int height, int exactHeight)
{
	int	**new_map;

	if (exactHeight)
		new_map = malloc(sizeof(int *) * height);
	else
		new_map = malloc(sizeof(int *) * (height + 10));
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
	map->width = ft_get_width(columns);
	map->map[map->height - 1] = malloc(sizeof(int) * map->width);
	if (!(map->map[map->height - 1]))
	{
		free(line);
		ft_freesplit(columns);
		ft_exit(*fdf, ft_perror_errno(ERRNO_INSUFFICIENT_MEM) + 1);
	}
	i = -1;
	while (++i < map->width)
		map->map[map->height - 1][i] = ft_atoi(columns[i]);
	ft_freesplit(columns);
}

void	ft_parse_map(t_fdf *fdf, int fd)
{
	t_map	*map;
	char	*line;

	map = &fdf->map;
	map->map = 0;
	map->height = 0;
	line = get_next_line(fd);
	while (line && *line)
	{
		map->height++;
		if (!map->map || map->height % 10 == 0)
			map->map = ft_realloc(map, map->height, 0);
		if (!map->map)
			ft_exit(*fdf, ft_perror_errno(ERRNO_INSUFFICIENT_MEM) + 1);
		ft_parse_columns(map, line);
		line = get_next_line(fd);
	}
	map->map = ft_realloc(map, map->height, 1);
	if (!map->map)
		ft_exit(*fdf, ft_perror_errno(ERRNO_INSUFFICIENT_MEM) + 1);
	if (map->height <= 0 || map->width <= 0)
		ft_exit(*fdf, ft_perror(ERR_INV_FILE) + 1);
	if (KDEBUG)
		ft_display_parsed_map(*map);
}
