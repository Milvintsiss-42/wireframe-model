/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:17:13 by ple-stra          #+#    #+#             */
/*   Updated: 2022/03/16 22:09:17 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2dpt	pt2d_from_pt3d(t_fdf *fdf, t_3dpt pt3d)
{
	t_2dpt	pt2d;

	fdf->draw.rx = fdf->draw.rx % 360;
	fdf->draw.rx -= 180;
	fdf->draw.ry = fdf->draw.ry % 360;
	fdf->draw.ry -= 180;
	fdf->draw.rz = fdf->draw.rz % 360;
	fdf->draw.rz -= 180;
	pt2d.x = pt3d.x;
	pt2d.y = pt3d.y;
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
// 	pt2d.x = pt3d.x;
// 	pt2d.y = pt3d.y;
// 	pt3d.x = pt3d.x * (double)fdf->draw.rx / 180;
// 	pt3d.y = pt3d.y * (double)fdf->draw.ry / 180;
// 	pt3d.z = pt3d.z * (double)fdf->draw.rz / 180;
// 	pt2d.x = pt3d.x * pt3d.z;
// 	pt2d.y = pt3d.y * pt3d.z;
// 	fdf->draw.rx += 180;
// 	fdf->draw.ry += 180;
// 	fdf->draw.rz += 180;
// 	return (pt2d);
// }
