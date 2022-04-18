/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:33:48 by ple-stra          #+#    #+#             */
/*   Updated: 2022/04/18 05:06:56 by ple-stra         ###   ########.fr       */
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
	draw->screentx = fdf->mlx.win_width / 2;
	draw->screenty = fdf->mlx.win_height / 2;
	draw->rx = 90;
	draw->ry = 90;
	draw->rz = 90;
	draw->tx = 0;
	draw->ty = 0;
	draw->tz = 0;
}

void	ft_update_zoom(t_fdf *fdf, int zoom)
{
	int	rtx;
	int	rty;

	if (zoom < 1)
		return ;
	rtx = fdf->draw.screentx - fdf->mlx.win_width / 2;
	rty = fdf->draw.screenty - fdf->mlx.win_height / 2;
	fdf->draw.zm = zoom;
	fdf->draw.screentx = rtx + fdf->mlx.win_width / 2;
	fdf->draw.screenty = rty + fdf->mlx.win_height / 2;
}
