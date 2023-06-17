/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:54:10 by ple-stra          #+#    #+#             */
/*   Updated: 2023/06/17 12:27:25 by ladloff          ###   ########.fr       */
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
