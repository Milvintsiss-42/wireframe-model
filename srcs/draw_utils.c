/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:33:48 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/06 05:16:45 by ple-stra         ###   ########.fr       */
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
	if (draw->zm < 1)
		draw->zm = ZINCREMENT;
	draw->screentx = fdf->mlx.win_width / 2;
	draw->screenty = fdf->mlx.win_height / 2;
	draw->rx = 270;
	draw->ry = 270;
	draw->rz = 270;
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
