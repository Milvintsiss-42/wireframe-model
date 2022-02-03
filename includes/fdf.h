/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 01:38:38 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/03 03:13:32 by ple-stra         ###   ########.fr       */
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
# define ERR_INV_FILE "Error: Invalid file\n"
# define ERRNO_CANT_OPEN_FILE "Error: Cannot open file"
# define ERRNO_INSUFFICIENT_MEM "Error: Insufficient memory"

# define ERR_FAILED_INIT_MLX "Error: Failed to init mlx"
# define ERR_FAILED_OP_WINDOW_MLX "Error: Failed to open mlx window"

# define WINDOW_TITLE "fdf"
# define WINDOW_HEIGHT 500
# define WINDOW_WIDTH 500

# define KEY_ECHAP 0xff1b
# define KEY_ARROW_L 0xff51
# define KEY_ARROW_R 0xff53
# define KEY_ARROW_T 0xff52
# define KEY_ARROW_D 0xff54

# ifndef KDEBUG
#  define KDEBUG 0
# endif

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

int			ft_display_map(t_fdf *fdf);

int			ft_on_keypressed(int key, t_fdf *fdf);
int			ft_on_echap_keypressed(t_fdf *fdf);
int			ft_on_arrowl_keypressed(t_fdf *fdf);
int			ft_on_arrowr_keypressed(t_fdf *fdf);
int			ft_on_arrowt_keypressed(t_fdf *fdf);
int			ft_on_arrowd_keypressed(t_fdf *fdf);

#endif