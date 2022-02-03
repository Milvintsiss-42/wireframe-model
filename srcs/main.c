/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 01:54:20 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/03 01:29:43 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_verify_args(int argc, char **argv)
{
	if (argc != 2)
		return (ft_perror(ERR_WRG_NB_ARG));
	if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1]))
		!= (argv[1] + ft_strlen(argv[1]) - 4))
		return (ft_perror(ERR_INV_EXT));
	return (1);
}

int	ft_open_map_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ft_perror_errno(ERRNO_CANT_OPEN_FILE) - 1);
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	fdf;

	if (!ft_verify_args(argc, argv))
		return (1);
	fd = ft_open_map_file(argv[1]);
	if (fd == -1)
		return (1);
	if (!ft_parse_map(&fdf.map, fd))
		return (1);
	if (!ft_display_map(&fdf))
		return (ft_freeall(fdf) + 1);
	return (ft_freeall(fdf));
}
