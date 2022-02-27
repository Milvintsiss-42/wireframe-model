/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_events_zoom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:51:19 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/27 23:19:22 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_on_plus_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("PLUS key pressed \n");
	ft_update_zoom(fdf, fdf->draw.zm + ZINCREMENT);
}

void	ft_on_minus_keypressed(t_fdf *fdf)
{
	if (KDEBUG)
		ft_putstr("MINUS key pressed \n");
	ft_update_zoom(fdf, fdf->draw.zm - ZINCREMENT);
}
