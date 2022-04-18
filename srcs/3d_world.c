/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:17:13 by ple-stra          #+#    #+#             */
/*   Updated: 2022/04/18 05:03:48 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	degree_to_radian(double x)
{
	return (x * PI / 180);
}

t_2dpt	pt2d_from_pt3d(t_fdf *fdf, t_3dpt pt3d)
{
	t_2dpt	pt2d;
	double	rot;
	double	rx;
	double	ry;

	fdf->draw.rx = fdf->draw.rx % 360;
	fdf->draw.rx -= 180;
	fdf->draw.ry = fdf->draw.ry % 360;
	fdf->draw.ry -= 180;
	fdf->draw.rz = fdf->draw.rz % 360;
	fdf->draw.rz -= 180;
	pt3d.x += fdf->draw.tx;
	pt3d.y += fdf->draw.ty;
	pt3d.z += fdf->draw.tz;
	pt3d.y -= pt3d.z / 32;
	rot = degree_to_radian(fdf->draw.rz);
	rx = (pt3d.x * cos(rot)) - (pt3d.y * sin(rot));
	ry = (pt3d.x * sin(rot)) - (pt3d.y * cos(rot));
	pt2d.x = rx * 0.5 + ry * -0.5;
	pt2d.y = rx * 0.25 + ry * 0.25 - pt3d.z / 32;
	fdf->draw.rx += 180;
	fdf->draw.ry += 180;
	fdf->draw.rz += 180;
	return (pt2d);
}

// t_2dpt	pt2d_from_pt3d(t_fdf *fdf, t_3dpt pt3d)
// {
// 	t_2dpt	pt2d;

// 	fdf->draw.rx = fdf->draw.rx % 360;
// 	fdf->draw.rx -= 180;
// 	fdf->draw.ry = fdf->draw.ry % 360;
// 	fdf->draw.ry -= 180;
// 	fdf->draw.rz = fdf->draw.rz % 360;
// 	fdf->draw.rz -= 180;
// 	pt2d.x = pt3d.x * 0.5 + pt3d.y * -0.5;
// 	pt2d.y = pt3d.x * 0.25 + pt3d.y * 0.25 - pt3d.z / 32;
// 	fdf->draw.rx += 180;
// 	fdf->draw.ry += 180;
// 	fdf->draw.rz += 180;
// 	return (pt2d);
// }
