/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_modes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:03:30 by ple-stra          #+#    #+#             */
/*   Updated: 2022/03/21 16:42:50 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_on_zoom_mode_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ZOOM MODE key pressed \n");
	fdf->key_mode = KEY_MODE_ZOOM;
}

static void	ft_on_rotate_mode_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ROTATE MODE key pressed \n");
	fdf->key_mode = KEY_MODE_ROTATE;
}

static void	ft_on_translate_mode_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("TRANSLATE MODE key pressed \n");
	fdf->key_mode = KEY_MODE_TRANSLATE;
}

void	ft_on_keymode_keypressed(t_fdf *fdf, int key)
{
	if (key == KEY_ZOOM)
		ft_on_zoom_mode_keypressed(fdf);
	else if (key == KEY_ROTATE)
		ft_on_rotate_mode_keypressed(fdf);
	else if (key == KEY_TRANSLATE)
		ft_on_translate_mode_keypressed(fdf);
}
