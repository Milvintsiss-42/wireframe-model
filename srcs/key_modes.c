/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_modes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:03:30 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/28 21:23:08 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_on_zoom_mode_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ZOOM MODE key pressed \n");
	fdf->key_mode = KEY_MODE_ZOOM;
}

static void	ft_on_rotate_x_mode_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ROTATE_X MODE key pressed \n");
	fdf->key_mode = KEY_MODE_ROTATION_X;
}

static void	ft_on_rotate_y_mode_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ROTATE_Y MODE key pressed \n");
	fdf->key_mode = KEY_MODE_ROTATION_Y;
}

static void	ft_on_rotate_z_mode_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ROTATE_Z MODE key pressed \n");
	fdf->key_mode = KEY_MODE_ROTATION_Z;
}

void	ft_on_keymode_keypressed(t_fdf *fdf, int key)
{
	if (key == KEY_ZOOM)
		ft_on_zoom_mode_keypressed(fdf);
	else if (key == KEY_ROTATE_X)
		ft_on_rotate_x_mode_keypressed(fdf);
	else if (key == KEY_ROTATE_Y)
		ft_on_rotate_y_mode_keypressed(fdf);
	else if (key == KEY_ROTATE_Z)
		ft_on_rotate_z_mode_keypressed(fdf);
}
