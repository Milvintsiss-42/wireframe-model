/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:15:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/04/16 03:32:44 by ple-stra         ###   ########.fr       */
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
	else if (key == KEY_PLUS)
		ft_on_plus_keypressed(fdf);
	else if (key == KEY_MINUS)
		ft_on_minus_keypressed(fdf);
	else if (key == KEY_ZOOM || key == KEY_TRANSLATE || key == KEY_ROTATE)
		ft_on_keymode_keypressed(fdf, key);
	else if (key == KEY_X || key == KEY_Y || key == KEY_Z)
		ft_on_keymode_axis_keypressed(fdf, key);
	if (key == KEY_ARROW_L || key == KEY_ARROW_R || key == KEY_ARROW_T
		|| key == KEY_ARROW_D || key == KEY_PLUS || key == KEY_MINUS)
		ft_reframe(fdf);
	return (0);
}

void	ft_on_echap_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ECHAP key pressed \n");
	ft_exit(*fdf, 0);
}
