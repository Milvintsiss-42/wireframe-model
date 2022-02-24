/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:15:59 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/24 19:43:52 by ple-stra         ###   ########.fr       */
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
}

int	ft_on_echap_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("ECHAP key pressed \n");
	ft_freeall(*fdf);
	exit(0);
}
