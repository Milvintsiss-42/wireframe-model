/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 01:54:20 by ple-stra          #+#    #+#             */
/*   Updated: 2022/05/08 18:37:02 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_fdf_values(t_fdf *fdf)
{
	fdf->img.current = ft_get_null_img();
	fdf->img.future = ft_get_null_img();
	fdf->map.map = 0;
	fdf->map.depth_max = 0;
	fdf->map.depth_min = 0;
	fdf->mlx.mlx = 0;
	fdf->mlx.window = 0;
	fdf->key_mode = KEY_MODE_ROTATE;
	fdf->key_mode_axis = KEY_MODE_AXIS_Z;
	fdf->projection_mode = ISOMETRIC_PROJECTION;
}

static void	ft_verify_args(int argc, char **argv)
{
	if (argc != 2)
		exit(ft_perror(ERR_WRG_NB_ARG));
	if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]))
		!= (argv[1] + ft_strlen(argv[1]) - 4))
		exit(ft_perror(ERR_INV_EXT));
}

static int	ft_open_map_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit(ft_perror_errno(ERRNO_CANT_OPEN_FILE));
	return (fd);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_init_fdf_values(&fdf);
	ft_verify_args(argc, argv);
	ft_parse_map(&fdf, ft_open_map_file(argv[1]));
	ft_display_map(&fdf);
	ft_exit(fdf, 0);
	return (0);
}
