/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:42:21 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/31 09:44:34 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_parsed_map(t_map map)
{
	int	i;
	int	j;

	printf("\n//////////////////////////////////////////////////\n\n");
	printf("Height: %d\n", map.height);
	printf("Width: %d\n", map.width);
	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
			printf("| %d ", map.map[i][j]);
		printf("|\n");
	}
	printf("\n//////////////////////////////////////////////////\n\n");
}
