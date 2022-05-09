/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:21:11 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/08 20:40:01 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_rot
{
	double	x;
	double	y;
	double	z;
}	t_rot;

static double	degree_to_radian(double x)
{
	return (x * PI / 180);
}

t_3dpt	apply_rotations(t_fdf *fdf, t_3dpt pt3d)
{
	t_rot	r;
	double	rx;
	double	ry;
	double	rz;

	fdf->draw.rx = fdf->draw.rx % 360;
	fdf->draw.ry = fdf->draw.ry % 360;
	fdf->draw.rz = fdf->draw.rz % 360;
	r.x = degree_to_radian(fdf->draw.rx);
	r.y = degree_to_radian(fdf->draw.ry);
	r.z = degree_to_radian(fdf->draw.rz);
	rx = pt3d.x * cos(r.y) * cos(r.z)
		+ pt3d.y * (-cos(r.x) * sin(r.z) + sin(r.x) * sin(r.y) * cos(r.z))
		+ pt3d.z * (sin(r.x) * sin(r.z) + cos(r.x) * sin(r.y) * cos(r.z));
	ry = pt3d.x * cos(r.y) * sin(r.z)
		+ pt3d.y * (cos(r.x) * cos(r.z) + sin(r.x) * sin(r.y) * sin(r.z))
		+ pt3d.z * (-sin(r.x) * cos(r.z) + cos(r.x) * sin(r.y) * sin(r.z));
	rz = pt3d.x * -sin(r.y)
		+ pt3d.y * sin(r.x) * cos(r.y)
		+ pt3d.z * cos(r.x) * cos(r.y);
	pt3d.x = rx;
	pt3d.y = ry;
	pt3d.z = rz;
	return (pt3d);
}

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
