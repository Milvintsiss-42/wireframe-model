/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:17:13 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/08 17:55:25 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_3dpt	apply_translations(t_fdf *fdf, t_3dpt pt3d)
{
	pt3d.x += fdf->draw.tx;
	pt3d.y += fdf->draw.ty;
	pt3d.z += fdf->draw.tz;
	return (pt3d);
}

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

static t_3dpt	apply_rotations(t_fdf *fdf, t_3dpt pt3d)
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

t_2dpt	pt2d_from_pt3d(t_fdf *fdf, t_3dpt pt3d)
{
	t_2dpt	pt2d;

	pt3d = apply_translations(fdf, pt3d);
	pt3d.z /= 24;
	pt3d = apply_rotations(fdf, pt3d);
	pt2d.x = pt3d.x * 0.5 + pt3d.y * -0.5;
	pt2d.y = pt3d.x * 0.25 + pt3d.y * 0.25 - pt3d.z;
	return (pt2d);
}
