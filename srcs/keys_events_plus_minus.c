/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_events_plus_minus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:51:19 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/28 21:15:42 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_on_plus_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("PLUS key pressed \n");
	if (fdf->key_mode == KEY_MODE_ZOOM)
		ft_update_zoom(fdf, fdf->draw.zm + ZINCREMENT);
	else if (fdf->key_mode == KEY_MODE_ROTATION_X)
		fdf->draw.rx += 5;
	else if (fdf->key_mode == KEY_MODE_ROTATION_Y)
		fdf->draw.ry += 5;
	else if (fdf->key_mode == KEY_MODE_ROTATION_Z)
		fdf->draw.rz += 5;
}

void	ft_on_minus_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("MINUS key pressed \n");
	if (fdf->key_mode == KEY_MODE_ZOOM)
		ft_update_zoom(fdf, fdf->draw.zm - ZINCREMENT);
	else if (fdf->key_mode == KEY_MODE_ROTATION_X)
		fdf->draw.rx -= 5;
	else if (fdf->key_mode == KEY_MODE_ROTATION_Y)
		fdf->draw.ry -= 5;
	else if (fdf->key_mode == KEY_MODE_ROTATION_Z)
		fdf->draw.rz -= 5;
}
