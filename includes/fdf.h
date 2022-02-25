/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 01:38:38 by ple-stra          #+#    #+#             */
/*   Updated: 2022/02/25 07:33:21 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define PROGRAM_NAME "fdf"

# define ERR_WRG_NB_ARG			"Error: Incorrect number of arguments\n"
# define ERR_INV_EXT			"Error: Invalid file extension\n"
# define ERR_INV_FILE			"Error: Invalid file\n"
# define ERRNO_CANT_OPEN_FILE	"Error: Cannot open file"
# define ERRNO_INSUFFICIENT_MEM	"Error: Insufficient memory"

# define ERR_FAILED_INIT_MLX	"Error: Failed to init mlx"
# define ERR_FAILED_OP_WIN_MLX	"Error: Failed to open mlx window"
# define ERR_MLXCRASH			"Error: MLX crashed"

# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF

# define KEY_ECHAP		0xff1b
# define KEY_ARROW_L	0xff51
# define KEY_ARROW_R	0xff53
# define KEY_ARROW_T	0xff52
# define KEY_ARROW_D	0xff54

# ifndef KDEBUG
#  define KDEBUG 0
# endif

typedef struct s_point {
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_map {
	int	height;
	int	width;
	int	**map;
}	t_map;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_img_garbage {
	t_img	current;
	t_img	future;
}	t_img_garbage;

typedef struct s_mlx {
	void	*mlx;
	void	*window;
	int		win_height;
	int		win_width;
}	t_mlx;

typedef struct s_draw {
	int		zm;
	int		tx;
	int		ty;
}	t_draw;

typedef struct s_fdf {
	t_map			map;
	t_mlx			mlx;
	t_img_garbage	img;
	t_draw			draw;
}	t_fdf;

int			ft_perror(char *error_str);
int			ft_perror_errno(char *error_str);

void		ft_parse_map(t_fdf *fdf, int fd);

void		ft_destroy_img(t_mlx mlx, t_img img);
void		ft_freemap(t_map map);
void		ft_freeall(t_fdf fdf);
void		ft_exit(t_fdf fdf, int status);

void		ft_display_parsed_map(t_map map);

void		ft_display_map(t_fdf *fdf);
void		ft_reframe(t_fdf *fdf);

void		ft_draw(t_fdf *fdf, t_img *img);

int			ft_on_keypressed(int key, t_fdf *fdf);
int			ft_on_echap_keypressed(t_fdf *fdf);
int			ft_on_arrowl_keypressed(t_fdf *fdf);
int			ft_on_arrowr_keypressed(t_fdf *fdf);
int			ft_on_arrowt_keypressed(t_fdf *fdf);
int			ft_on_arrowd_keypressed(t_fdf *fdf);

t_img		ft_create_empty_img(t_fdf fdf);
t_img		ft_get_null_img(void);
void		ft_create_new_fdf_img(t_fdf *fdf);
void		ft_set_future_fdf_img(t_fdf *fdf, t_img img);
void		ft_set_new_img_to_screen(t_fdf *fdf);

void		ft_put_pixel_on_img(t_img img, int x, int y, int color);
void		ft_draw_line(t_img img, t_point p1, t_point p2);

#endif