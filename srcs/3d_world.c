/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:17:13 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/09 17:03:06 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_2dpt	isometric_projection(t_3dpt pt3d)
{
	t_2dpt	pt2d;

	pt2d.x = pt3d.x * 0.5 + pt3d.y * -0.5;
	pt2d.y = pt3d.x * 0.25 + pt3d.y * 0.25 - pt3d.z;
	return (pt2d);
}

static t_2dpt	perspective_projection(t_fdf *fdf, t_3dpt pt3d)
{
	t_2dpt	pt2d;
	double	f;

	f = fdf->map.width;
	if (fdf->map.depth_max != 0 || fdf->map.depth_min != 0)
		pt3d.z = (fdf->map.depth_max + fdf->map.depth_min) - pt3d.z;
	else
		pt3d.z = 1;
	if (pt3d.z < 0)
	{
		pt2d.x = -1;
		pt2d.y = -1;
		return (pt2d);
	}
	if (pt3d.z == 0)
		pt3d.z = 0.1;
	pt2d.x = pt3d.x * f / pt3d.z;
	pt2d.y = pt3d.y * f / pt3d.z;
	return (pt2d);
}

t_2dpt	pt2d_from_pt3d(t_fdf *fdf, t_3dpt pt3d)
{
	pt3d = apply_translations(fdf, pt3d);
	pt3d.z /= fdf->draw.fheight;
	if (fdf->projection_mode == FLAT_ISO_PROJECTION)
		pt3d.z = 0;
	pt3d = apply_rotations(fdf, pt3d);
	if (fdf->projection_mode == ISOMETRIC_PROJECTION)
		return (isometric_projection(pt3d));
	else if (fdf->projection_mode == PERSPECTIVE_PROJECTION)
		return (perspective_projection(fdf, pt3d));
	else
		return (isometric_projection(pt3d));
}
