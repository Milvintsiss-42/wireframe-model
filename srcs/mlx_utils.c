/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:31:31 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/27 20:43:20 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	t_img	img;
	char	*dest;

	img = fdf->img.future;
	x += fdf->draw.tx;
	y += fdf->draw.ty;
	if (x >= 0 && x < fdf->mlx.win_width && y >= 0 && y < fdf->mlx.win_height)
	{
		dest = img.addr + (y * img.line_len + x * (img.bits_per_pixel / 8));
		*(unsigned int *)dest = color;
	}
}

double	ft_positive(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	double	max_dist;
	double	dirx;
	double	diry;
	double	distx;
	double	disty;

	p1.x *= fdf->draw.zm;
	p1.y *= fdf->draw.zm;
	p2.x *= fdf->draw.zm;
	p2.y *= fdf->draw.zm;
	distx = ft_positive(p2.x - p1.x);
	disty = ft_positive(p2.y - p1.y);
	max_dist = ft_max((int)distx, (int)disty);
	dirx = (p2.x - p1.x > 0) * 2 - 1;
	diry = (p2.y - p1.y > 0) * 2 - 1;
	dirx *= distx / max_dist;
	diry *= disty / max_dist;
	while (max_dist--)
	{
		ft_put_pixel_on_img(fdf, (int)p1.x, (int)p1.y, WHITE);
		p1.x += dirx;
		p1.y += diry;
	}
}

double	ft_dist(t_point p1, t_point p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}
