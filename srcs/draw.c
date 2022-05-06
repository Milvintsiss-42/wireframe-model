/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 07:20:28 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/06 01:51:22 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// t_img	colored_map_img(t_fdf fdf)
// {
// 	t_img	img;
// 	int		x;
// 	int		y;
// 	int		color;

// 	img = ft_create_empty_img(fdf);
// 	x = fdf.mlx.win_width;
// 	while (x--)
// 	{
// 		y = fdf.mlx.win_height;
// 		while (y--)
// 		{
// 			color = (x * 255) / fdf.mlx.win_width
// 				+ ((((fdf.mlx.win_width - x) * 255) / fdf.mlx.win_width) << 16)
// 				+ (((y * 255) / fdf.mlx.win_height) << 8);
// 			ft_put_pixel_on_img(&fdf, x, y, color);
// 		}
// 	}
// 	return (img);
// }

static t_3dpt	ft_pt(t_fdf fdf, int x, int y, t_map_elem map_elem)
{
	t_3dpt	pt;

	pt.x = x - fdf.map.width / 2;
	pt.y = y - fdf.map.height / 2;
	pt.z = map_elem.height;
	if (map_elem.has_color)
	{
		pt.color = map_elem.color;
		pt.has_color = 1;
	}
	else
		pt.has_color = 0;
	return (pt);
}

static int	is_in_bounds(t_fdf *fdf, t_2dpt p)
{
	return (p.x + fdf->draw.screentx >= 0
		&& p.x + fdf->draw.screentx < fdf->mlx.win_width
		&& p.y + fdf->draw.screenty >= 0
		&& p.y + fdf->draw.screenty < fdf->mlx.win_height);
}

static void	ft_draw_3d_line(t_fdf *fdf, t_3dpt pt1, t_3dpt pt2)
{
	t_2dpt	p1;
	t_2dpt	p2;

	p1 = pt2d_from_pt3d(fdf, pt1);
	p2 = pt2d_from_pt3d(fdf, pt2);
	p1.x *= fdf->draw.zm;
	p1.y *= fdf->draw.zm;
	p2.x *= fdf->draw.zm;
	p2.y *= fdf->draw.zm;
	if (is_in_bounds(fdf, p1) && is_in_bounds(fdf, p2))
		ft_draw_line(fdf, p1, p2, ft_get_gradient(fdf, pt1, pt2));
}

void	ft_draw(t_fdf *fdf)
{
	int		x;
	int		y;
	t_3dpt	pt1;

	x = -1;
	while (++x < fdf->map.width)
	{
		y = -1;
		while (++y < fdf->map.height)
		{
			pt1 = ft_pt(*fdf, x, y, fdf->map.map[y][x]);
			if (x < fdf->map.width - 1)
				ft_draw_3d_line(fdf,
					pt1, ft_pt(*fdf, x + 1, y, fdf->map.map[y][x + 1]));
			if (y < fdf->map.height - 1)
				ft_draw_3d_line(fdf,
					pt1, ft_pt(*fdf, x, y + 1, fdf->map.map[y + 1][x]));
		}
	}
}
