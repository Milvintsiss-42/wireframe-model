/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:31:31 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/25 05:34:03 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel_on_img(t_img img, int x, int y, int color)
{
	char	*dest;

	dest = img.addr + (y * img.line_len + x * (img.bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

double	ft_positive(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_draw_line(t_img img, t_point p1, t_point p2)
{
	double	max_dist;
	double	dirx;
	double	diry;
	double	distx;
	double	disty;

	distx = ft_positive(p2.x - p1.x);
	disty = ft_positive(p2.y - p1.y);
	max_dist = ft_max((int)distx, (int)disty);
	dirx = (p2.x - p1.x > 0) * 2 - 1;
	diry = (p2.y - p1.y > 0) * 2 - 1;
	dirx *= distx / max_dist;
	diry *= disty / max_dist;
	while (max_dist--)
	{
		ft_put_pixel_on_img(img, (int)p1.x, (int)p1.y, WHITE);
		p1.x += dirx;
		p1.y += diry;
	}
}

double	ft_dist(t_point p1, t_point p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}
