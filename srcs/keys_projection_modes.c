/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_projection_modes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:27:33 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/09 17:27:32 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_projection_rotation(t_fdf *fdf, int key)
{
	if ((key == KEY_ISOMETRIC || key == KEY_FLAT_ISO)
		&& fdf->projection_mode == PERSPECTIVE_PROJECTION)
	{
		fdf->draw.rx = 0;
		fdf->draw.ry = 0;
		fdf->draw.rz = 0;
	}
	else if (key == KEY_PERSPECT
		&& (fdf->projection_mode == ISOMETRIC_PROJECTION
			|| fdf->projection_mode == FLAT_ISO_PROJECTION))
	{
		fdf->draw.rx = 50;
		fdf->draw.ry = 0;
		fdf->draw.rz = 0;
	}
}

void	ft_on_projection_mode_keypressed(t_fdf *fdf, int key)
{
	set_projection_rotation(fdf, key);
	if (key == KEY_ISOMETRIC)
	{
		if (KDEBUG)
			ft_putstr("ISOMETRIC PROJECTION key pressed \n");
		fdf->projection_mode = ISOMETRIC_PROJECTION;
	}
	else if (key == KEY_FLAT_ISO)
	{
		if (KDEBUG)
			ft_putstr("FLAT_ISO PROJECTION key pressed \n");
		fdf->projection_mode = FLAT_ISO_PROJECTION;
	}
	else if (key == KEY_PERSPECT)
	{
		if (KDEBUG)
			ft_putstr("PERSPECTIVE PROJECTION key pressed \n");
		fdf->projection_mode = PERSPECTIVE_PROJECTION;
	}
	ft_reframe(fdf);
}
