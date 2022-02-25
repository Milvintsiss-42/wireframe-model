/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:42:21 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/24 21:12:44 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_parsed_map(t_map map)
{
	int	i;
	int	j;

	ft_printf("\n//////////////////////////////////////////////////\n\n");
	ft_printf("Height: %d\n", map.height);
	ft_printf("Width: %d\n", map.width);
	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
			ft_printf("| %02d ", map.map[i][j]);
		ft_printf("|\n");
	}
	ft_printf("\n//////////////////////////////////////////////////\n\n");
}
