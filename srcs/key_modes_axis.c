/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_modes_axis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:36:47 by ple-stra          #+#    #+#             */
/*   Updated: 2022/03/21 16:37:45 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_on_axis_x_mode_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ROTATE_X MODE key pressed \n");
	fdf->key_mode_axis = KEY_MODE_AXIS_X;
}

static void	ft_on_axis_y_mode_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ROTATE_Y MODE key pressed \n");
	fdf->key_mode_axis = KEY_MODE_AXIS_Y;
}

static void	ft_on_axis_z_mode_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ROTATE_Z MODE key pressed \n");
	fdf->key_mode_axis = KEY_MODE_AXIS_Z;
}

void	ft_on_keymode_axis_keypressed(t_fdf *fdf, int key)
{
	if (key == KEY_X)
		ft_on_axis_x_mode_keypressed(fdf);
	else if (key == KEY_Y)
		ft_on_axis_y_mode_keypressed(fdf);
	else if (key == KEY_Z)
		ft_on_axis_z_mode_keypressed(fdf);
}
