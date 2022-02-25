/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:54:10 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/25 00:27:12 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_destroy_img(t_mlx mlx, t_img img)
{
	if (img.img)
		mlx_destroy_image(mlx.mlx, img.img);
}

void	ft_freemap(t_map map)
{
	int	i;

	if (!map.map)
		return ;
	i = -1;
	while (++i < map.height)
		free(map.map[i]);
	free(map.map);
}

static void	ft_freemlx(t_mlx mlx)
{
	if (mlx.mlx)
	{
		if (mlx.window)
			mlx_destroy_window(mlx.mlx, mlx.window);
		mlx_destroy_display(mlx.mlx);
		free(mlx.mlx);
	}
}

void	ft_freeall(t_fdf fdf)
{
	ft_destroy_img(fdf.mlx, fdf.img.current);
	ft_destroy_img(fdf.mlx, fdf.img.future);
	ft_freemap(fdf.map);
	ft_freemlx(fdf.mlx);
}

void	ft_exit(t_fdf fdf, int status)
{
	ft_freeall(fdf);
	exit(status);
}
