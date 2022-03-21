/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_events_plus_minus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:51:19 by ple-stra          #+#    #+#             */
/*   Updated: 2022/03/21 19:58:12 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
}

void	ft_on_plus_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("PLUS key pressed \n");
	ft_rotate_or_translate_or_zoom(fdf, 1);
}

void	ft_on_minus_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("MINUS key pressed \n");
	ft_rotate_or_translate_or_zoom(fdf, -1);
}
