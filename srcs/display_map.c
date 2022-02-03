/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:55:02 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/03 03:13:32 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_map_1(void *mlx, void *win, int w, int h)
{
	int	x;
	int	y;
	int	color;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			color = (x * 255) / w + ((((w - x) * 255) / w) << 16)
				+ (((y * 255) / h) << 8);
			mlx_pixel_put(mlx, win, x, y, color);
		}
	}
}

int	ft_display_map(t_fdf *fdf)
{	
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	if (!mlx)
		return (ft_perror(ERR_FAILED_INIT_MLX));
	mlx_window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (!mlx_window)
		return (ft_perror(ERR_FAILED_OP_WINDOW_MLX));
	color_map_1(mlx, mlx_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_key_hook(mlx_window, ft_on_keypressed, fdf);
	mlx_loop(mlx);
}
