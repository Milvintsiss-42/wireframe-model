/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:21:41 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/08 18:39:54 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3dpt	apply_translations(t_fdf *fdf, t_3dpt pt3d)
{
	pt3d.x += fdf->draw.tx;
	pt3d.y += fdf->draw.ty;
	pt3d.z += fdf->draw.tz;
	return (pt3d);
}

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
