/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:44:16 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/06 05:47:41 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	use_hex_caps(char *color)
{
	char	*caps;
	int		i;

	caps = "ABCDEF";
	while (*color)
	{
		i = 0;
		while (*color != caps[i] && caps[i])
			i++;
		if (caps[i])
			return (1);
		if (!ft_isdigit(*color))
			return (0);
		color++;
	}
	return (0);
}

t_map_elem	ft_parse_point(char *point)
{
	t_map_elem	map_elem;

	map_elem.height = ft_atoi(point);
	while (ft_isdigit(*point))
		point++;
	map_elem.has_color = *point == ',';
	if (map_elem.has_color)
	{
		point += 3;
		if (use_hex_caps(point))
			map_elem.color = ft_baseatoi(point, HEX_BASE_CAPS);
		else
			map_elem.color = ft_baseatoi(point, HEX_BASE);
	}
	return (map_elem);
}
