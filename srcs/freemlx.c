/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:27:42 by ladloff           #+#    #+#             */
/*   Updated: 2023/06/17 12:30:32 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#ifdef __linux__

void	ft_freemlx(t_mlx mlx)
{
	if (mlx.mlx)
	{
		if (mlx.window)
			mlx_destroy_window(mlx.mlx, mlx.window);
		mlx_destroy_display(mlx.mlx);
		free(mlx.mlx);
	}
}

#elif __APPLE__

void	ft_freemlx(t_mlx mlx)
{
	if (mlx.mlx)
	{
		if (mlx.window)
			mlx_destroy_window(mlx.mlx, mlx.window);
		free(mlx.mlx);
	}
}

#endif
