/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradients.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:48:10 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/06 04:06:27 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_color_mix(int color1, int color2, double mix)
{
	int	r;
	int	g;
	int	b;

	r = (color1 >> 16) * (1 - mix) + (color2 >> 16) * mix;
	g = ((color1 >> 8) & 0x0000ff) * (1 - mix)
		+ ((color2 >> 8) & 0x0000ff) * mix;
	b = (color1 & 0x0000ff) * (1 - mix)
		+ (color2 & 0x0000ff) * mix;
	return ((r << 16) + (g << 8) + b);
}

t_gradient	ft_get_gradient(t_fdf *fdf, t_3dpt pt1, t_3dpt pt2)
{
	t_gradient	gradient;
	int			depth_diff;

	depth_diff = fdf->map.depth_max - fdf->map.depth_min;
	if (pt1.has_color && USE_EXTERNAL_COLORS)
		gradient.color1 = pt1.color;
	else if (depth_diff != 0)
		gradient.color1
			= ft_color_mix(LOW_COLOR, HIGH_COLOR,
				(pt1.z - fdf->map.depth_min) / depth_diff);
	else
		gradient.color1 = LOW_COLOR;
	if (pt2.has_color && USE_EXTERNAL_COLORS)
		gradient.color2 = pt2.color;
	else if (depth_diff != 0)
		gradient.color2
			= ft_color_mix(LOW_COLOR, HIGH_COLOR,
				(pt2.z - fdf->map.depth_min) / depth_diff);
	else
		gradient.color2 = LOW_COLOR;
	return (gradient);
}
