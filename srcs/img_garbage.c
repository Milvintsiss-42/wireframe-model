/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_garbage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:06:15 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/25 05:34:37 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	ft_get_null_img(void)
{
	t_img	img;

	img.img = 0;
	img.addr = 0;
	img.bits_per_pixel = 0;
	img.endian = 0;
	img.line_len = 0;
	return (img);
}

void	ft_create_new_fdf_img(t_fdf *fdf)
{
	if (fdf->img.future.img != 0)
		ft_destroy_img(fdf->mlx, fdf->img.future);
	fdf->img.future = ft_create_empty_img(*fdf);
}

void	ft_set_future_fdf_img(t_fdf *fdf, t_img img)
{
	if (fdf->img.future.img != 0)
		ft_destroy_img(fdf->mlx, fdf->img.future);
	fdf->img.future = img;
}

t_img	ft_create_empty_img(t_fdf fdf)
{
	t_img	img;

	img.img = mlx_new_image(fdf.mlx.mlx, fdf.mlx.win_width, fdf.mlx.win_height);
	if (!img.img)
		ft_exit(fdf, ft_perror(ERR_MLXCRASH));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len,
			&img.endian);
	if (!img.addr)
	{
		mlx_destroy_image(fdf.mlx.mlx, img.img);
		ft_exit(fdf, ft_perror(ERR_MLXCRASH));
	}
	return (img);
}

void	ft_set_new_img_to_screen(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx.mlx, fdf->mlx.window, fdf->img.future.img,
		0, 0);
	ft_destroy_img(fdf->mlx, fdf->img.current);
	fdf->img.current = fdf->img.future;
	fdf->img.future = ft_get_null_img();
}
