/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:42:21 by ple-stra          #+#    #+#             */
/*   Updated: 2022/03/21 19:55:04 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display_parsed_map(t_map map)
{
	int	i;
	int	j;

	if (!KDEBUG)
		return ;
	ft_printf("\n//////////////////////////////////////////////////\n\n");
	ft_printf("Height: %d\n", map.height);
	ft_printf("Width: %d\n", map.width);
	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
			ft_printf("| %02d ", map.map[i][j]);
		ft_printf("|\n");
	}
	ft_printf("\n//////////////////////////////////////////////////\n\n");
}

void	ft_print_draw_debug_info(t_fdf *fdf)
{
	if (!KDEBUG)
		return ;
	ft_printf("\n------REDRAW------\n\n");
	ft_printf("tx: %3d\n", fdf->draw.tx);
	ft_printf("ty: %3d\n", fdf->draw.ty);
	ft_printf("tz: %3d\n\n", fdf->draw.tz);
	ft_printf("rx: %3d\n", fdf->draw.rx);
	ft_printf("ry: %3d\n", fdf->draw.ry);
	ft_printf("rz: %3d\n", fdf->draw.rz);
	ft_printf("\n------------------\n\n");
}
