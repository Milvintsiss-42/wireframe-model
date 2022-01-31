/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:54:10 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/31 09:57:55 by ple-stra         ###   ########.fr       */
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

int	ft_freeall(t_fdf fdf)
{
	ft_freemap(fdf.map);
	return (0);
}
