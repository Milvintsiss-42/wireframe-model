/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:21:11 by ple-stra          #+#    #+#             */
/*   Updated: 2022/03/21 16:31:21 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rotation_of_current_axis(t_fdf *fdf)
{
	if (fdf->key_mode_axis == KEY_MODE_AXIS_X)
		return (fdf->draw.rx);
	else if (fdf->key_mode_axis == KEY_MODE_AXIS_Y)
		return (fdf->draw.ry);
	else if (fdf->key_mode_axis == KEY_MODE_AXIS_Z)
		return (fdf->draw.rz);
	return (0);
}

void	ft_update_rotation(t_fdf *fdf, int rotation)
{
	if (fdf->key_mode_axis == KEY_MODE_AXIS_X)
		fdf->draw.rx = rotation;
	else if (fdf->key_mode_axis == KEY_MODE_AXIS_Y)
		fdf->draw.ry = rotation;
	else if (fdf->key_mode_axis == KEY_MODE_AXIS_Z)
		fdf->draw.rz = rotation;
}
