/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 01:38:38 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/31 09:58:13 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define ERR_WRG_NB_ARG "Error: Incorrect number of arguments\n"
# define ERR_INV_EXT "Error: Invalid file extension\n"
# define ERRNO_CANT_OPEN_FILE "Error: Cannot open file"
# define ERRNO_INSUFFICIENT_MEM "Error: Insufficient memory"

typedef struct s_map {
	int	height;
	int	width;
	int	**map;
}	t_map;

typedef struct s_fdf {
	t_map	map;
}	t_fdf;

int			ft_perror(char *error_str);
int			ft_perror_errno(char *error_str);

int			ft_parse_map(t_map *map, int fd);

int			ft_freemap(t_map map);
int			ft_freeall(t_fdf fdf);

void		ft_display_parsed_map(t_map map);

#endif