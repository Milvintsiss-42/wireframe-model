/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:33:48 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/28 16:04:10 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_fdf_draw_helpers(t_fdf *fdf)
{
	t_draw	*draw;

	draw = &fdf->draw;
	draw->fscreen
		= ft_min(fdf->mlx.win_height, fdf->mlx.win_width) / FSCREEN_DIVIDOR;
	draw->zm = ft_min(fdf->mlx.win_width / (fdf->map.width - 1),
			fdf->mlx.win_height / (fdf->map.height - 1)) * 2 / 3;
	draw->tx = fdf->mlx.win_width / 2;
	draw->ty = fdf->mlx.win_height / 2;
	draw->rx = 45;
	draw->ry = 45;
	draw->rz = 45;
}

void	ft_update_zoom(t_fdf *fdf, int zoom)
{
	int	rtx;
	int	rty;

	if (zoom < 1)
		return ;
	rtx = fdf->draw.tx - fdf->mlx.win_width / 2;
	rty = fdf->draw.ty - fdf->mlx.win_height / 2;
	fdf->draw.zm = zoom;
	fdf->draw.tx = rtx + fdf->mlx.win_width / 2;
	fdf->draw.ty = rty + fdf->mlx.win_height / 2;
}
