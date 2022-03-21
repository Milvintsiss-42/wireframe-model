/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:21:41 by ple-stra          #+#    #+#             */
/*   Updated: 2022/03/21 16:39:37 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_translation_of_current_axis(t_fdf *fdf)
{
	if (fdf->key_mode_axis == KEY_MODE_AXIS_X)
		return (fdf->draw.tx);
	else if (fdf->key_mode_axis == KEY_MODE_AXIS_Y)
		return (fdf->draw.ty);
	else if (fdf->key_mode_axis == KEY_MODE_AXIS_Z)
		return (fdf->draw.tz);
	return (0);
}

void	ft_update_translation(t_fdf *fdf, int translation)
{
	if (fdf->key_mode_axis == KEY_MODE_AXIS_X)
		fdf->draw.tx = translation;
	else if (fdf->key_mode_axis == KEY_MODE_AXIS_Y)
		fdf->draw.ty = translation;
	else if (fdf->key_mode_axis == KEY_MODE_AXIS_Z)
		fdf->draw.tz = translation;
}
