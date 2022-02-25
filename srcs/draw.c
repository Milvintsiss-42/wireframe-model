/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 07:20:28 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/25 07:32:14 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	colored_map_img(t_fdf fdf)
{
	t_img	img;
	int		x;
	int		y;
	int		color;

	img = ft_create_empty_img(fdf);
	x = fdf.mlx.win_width;
	while (x--)
	{
		y = fdf.mlx.win_height;
		while (y--)
		{
			color = (x * 255) / fdf.mlx.win_width
				+ ((((fdf.mlx.win_width - x) * 255) / fdf.mlx.win_width) << 16)
				+ (((y * 255) / fdf.mlx.win_height) << 8);
			ft_put_pixel_on_img(img, x, y, color);
		}
	}
	return (img);
}

static t_point	ft_pt1(t_fdf fdf, int x, int y)
{
	t_point	pt1;

	pt1.x = fdf.draw.zm * x + fdf.draw.tx;
	pt1.y = fdf.draw.zm * y + fdf.draw.ty;
	pt1.z = fdf.draw.zm * fdf.map.map[y][x];
	return (pt1);
}

static t_point	ft_pt2(t_fdf fdf, int x, int y)
{
	t_point	pt2;

	pt2.x = fdf.draw.zm * (x + 1) + fdf.draw.tx;
	pt2.y = fdf.draw.zm * y + fdf.draw.ty;
	pt2.z = fdf.draw.zm * fdf.map.map[y][x + 1];
	return (pt2);
}

static t_point	ft_pt3(t_fdf fdf, int x, int y)
{
	t_point	pt3;

	pt3.x = fdf.draw.zm * x + fdf.draw.tx;
	pt3.y = fdf.draw.zm * (y + 1) + fdf.draw.ty;
	pt3.z = fdf.draw.zm * fdf.map.map[y + 1][x];
	return (pt3);
}

void	ft_draw(t_fdf *fdf, t_img *img)
{
	int		x;
	int		y;
	t_point	pt1;

	x = -1;
	while (++x < fdf->map.width)
	{
		y = -1;
		while (++y < fdf->map.height)
		{
			pt1 = ft_pt1(*fdf, x, y);
			if (x != fdf->map.width - 1)
				ft_draw_line(*img, pt1, ft_pt2(*fdf, x, y));
			if (y != fdf->map.height - 1)
				ft_draw_line(*img, pt1, ft_pt3(*fdf, x, y));
		}
	}
}
