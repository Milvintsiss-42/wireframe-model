/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_events_plus_minus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:51:19 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/08 20:06:53 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_update_height_factor(t_fdf *fdf, int is_addition)
{
	if (fdf->draw.fheight > HEIGHT_INCREMENT && is_addition == 1)
		fdf->draw.fheight -= HEIGHT_INCREMENT;
	else if (is_addition == -1)
		fdf->draw.fheight += HEIGHT_INCREMENT;
}

static void	ft_rotate_or_translate_or_zoom(t_fdf *fdf, int is_addition)
{
	if (fdf->key_mode == KEY_MODE_TRANSLATE)
		ft_update_translation(fdf,
			get_translation_of_current_axis(fdf) + is_addition);
	else if (fdf->key_mode == KEY_MODE_ROTATE)
		ft_update_rotation(fdf,
			get_rotation_of_current_axis(fdf) + 5 * is_addition);
	else if (fdf->key_mode == KEY_MODE_ZOOM)
		ft_update_zoom(fdf, fdf->draw.zm + ZINCREMENT * is_addition);
	else if (fdf->key_mode == KEY_MODE_HEIGHT)
		ft_update_height_factor(fdf, is_addition);
}

void	ft_on_plus_or_minus_keypressed(t_fdf *fdf, int key)
{
	if (key == KEY_PLUS)
	{
		if (KDEBUG)
			ft_putstr("PLUS key pressed \n");
		ft_rotate_or_translate_or_zoom(fdf, 1);
	}
	else if (key == KEY_MINUS)
	{
		if (KDEBUG)
			ft_putstr("MINUS key pressed \n");
		ft_rotate_or_translate_or_zoom(fdf, -1);
	}
	ft_reframe(fdf);
}
