/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:31:31 by ple-stra          #+#    #+#             */
/*   Updated: 2022/04/16 05:50:15 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_pixel_on_img(t_fdf *fdf, int x, int y, int color)
{
	t_img	img;
	char	*dest;

	img = fdf->img.future;
	x += fdf->draw.screentx;
	y += fdf->draw.screenty;
	if (x >= 0 && x < fdf->mlx.win_width && y >= 0 && y < fdf->mlx.win_height)
	{
		dest = img.addr + (y * img.line_len + x * (img.bits_per_pixel / 8));
		*(unsigned int *)dest = color;
	}
}

static double	ft_positive(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static double	ft_dist(t_2dpt p1, t_2dpt p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)));
}

void	ft_draw_line(t_fdf *fdf, t_2dpt p1, t_2dpt p2, t_gradient gradient)
{
	double	max_dist;
	double	dirx;
	double	diry;
	double	init_dist;

	p1.x *= fdf->draw.zm;
	p1.y *= fdf->draw.zm;
	p2.x *= fdf->draw.zm;
	p2.y *= fdf->draw.zm;
	init_dist = ft_dist(p1, p2);
	max_dist
		= ft_max((int)ft_positive(p2.x - p1.x), (int)ft_positive(p2.y - p1.y));
	dirx = (p2.x - p1.x > 0) * 2 - 1;
	diry = (p2.y - p1.y > 0) * 2 - 1;
	dirx *= ft_positive(p2.x - p1.x) / max_dist;
	diry *= ft_positive(p2.y - p1.y) / max_dist;
	while (max_dist-- >= 0)
	{
		ft_put_pixel_on_img(fdf, (int)p1.x, (int)p1.y,
			ft_color_mix(gradient.color1, gradient.color2,
				1 - ft_dist(p1, p2) / init_dist));
		p1.x += dirx;
		p1.y += diry;
	}
}
