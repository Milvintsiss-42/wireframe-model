/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:15:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/09 17:39:08 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_on_keypressed(int key, t_fdf *fdf)
{
	if (KDEBUG)
		ft_printf("Pressed key: %#x\n", key);
	if (key == KEY_ECHAP)
		ft_on_echap_keypressed(fdf);
	else if (key == KEY_ARROW_L)
		ft_on_arrowl_keypressed(fdf);
	else if (key == KEY_ARROW_R)
		ft_on_arrowr_keypressed(fdf);
	else if (key == KEY_ARROW_T)
		ft_on_arrowt_keypressed(fdf);
	else if (key == KEY_ARROW_D)
		ft_on_arrowd_keypressed(fdf);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		ft_on_plus_or_minus_keypressed(fdf, key);
	else if (key == KEY_ZOOM || key == KEY_TRANSLATE || key == KEY_ROTATE
		|| key == KEY_HEIGHT)
		ft_on_keymode_keypressed(fdf, key);
	else if (key == KEY_X || key == KEY_Y || key == KEY_Z)
		ft_on_keymode_axis_keypressed(fdf, key);
	else if (key == KEY_ISOMETRIC || key == KEY_PERSPECT || key == KEY_FLAT_ISO)
		ft_on_projection_mode_keypressed(fdf, key);
	return (0);
}

void	ft_on_echap_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ECHAP key pressed \n");
	ft_exit(*fdf, 0);
}

int	ft_on_cross_clicked(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("Exit cross pressed \n");
	ft_exit(*fdf, 0);
	return (0);
}
