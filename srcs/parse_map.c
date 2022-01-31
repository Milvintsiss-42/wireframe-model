/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:09:44 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/31 08:00:57 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_freemap(t_map map)
{
	int	i;

	if (!map.map)
		return (0);
	i = -1;
	while (++i < map.height)
		free(map.map[i]);
	free(map.map);
	return (0);
}

void	ft_display_parsed_map(t_map map)
{
	int	i;
	int	j;

	printf("Height: %d\n", map.height);
	printf("Width: %d\n", map.width);
	printf("\n//////////////////////////////////////////////////\n\n");
	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
			printf("| %d ", map.map[i][j]);
		printf("|\n");
	}
}

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

int	ft_parse_map(t_map *map, int fd)
{
	char	*line;
	char	**columns;
	int		i;

	map->map = 0;
	map->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		if (!map->map || map->height % 10 == 0)
			map->map = ft_realloc(map, map->height, 0);
		if (!map->map)
			return (ft_perror_errno(ERRNO_INSUFFICIENT_MEM));
		columns = ft_split(line, ' ');
		free(line);
		if (!columns)
			return (ft_perror_errno(ERRNO_INSUFFICIENT_MEM));
		map->width = ft_get_width(columns);
		map->map[map->height - 1] = malloc(sizeof(int) * map->width);
		if (!(map->map[map->height - 1]))
		{
			free(line);
			ft_freesplit(columns);
			return (ft_freemap(*map));
		}
		i = -1;
		while (++i < map->width)
			map->map[map->height - 1][i] = ft_atoi(columns[i]);
		ft_freesplit(columns);
		line = get_next_line(fd);
	}
	map->map = ft_realloc(map, map->height, 1);
	if (!map->map)
		return (0);
	ft_display_parsed_map(*map);
	return (1);
}
