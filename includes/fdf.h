/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 01:38:38 by ple-stra          #+#    #+#             */
/*   Updated: 2022/03/06 21:03:53 by ple-stra         ###   ########.fr       */
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

# define FSCREEN_DIVIDOR	50
# define ZINCREMENT			2

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
# define KEY_ROTATE_X	0x0078
# define KEY_ROTATE_Y	0x0079
# define KEY_ROTATE_Z	0x007a
# define KEY_ZOOM		0x0070
# define KEY_ARROW_L	0xff51
# define KEY_ARROW_R	0xff53
# define KEY_ARROW_T	0xff52
# define KEY_ARROW_D	0xff54
# define KEY_MINUS		0x002d
# define KEY_PLUS		0x003d
# define KEY_ARROW_D	0xff54

# define KEY_MODE_ZOOM			0
# define KEY_MODE_ROTATION_X	1
# define KEY_MODE_ROTATION_Y	2
# define KEY_MODE_ROTATION_Z	3

# ifndef KDEBUG
#  define KDEBUG 0
# endif

typedef struct s_2dpoint {
	double	x;
	double	y;
	int		color;
}	t_2dpt;

typedef struct s_3dpoint {
	double	x;
	double	y;
	double	z;
}	t_3dpt;

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
	int		rx;
	int		ry;
	int		rz;
	int		fscreen;
}	t_draw;

typedef struct s_fdf {
	t_map			map;
	t_mlx			mlx;
	t_img_garbage	img;
	t_draw			draw;
	int				key_mode;
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

void		ft_draw(t_fdf *fdf);

int			ft_on_keypressed(int key, t_fdf *fdf);
void		ft_on_keymode_keypressed(t_fdf *fdf, int key);
void		ft_on_echap_keypressed(t_fdf *fdf);
void		ft_on_arrowl_keypressed(t_fdf *fdf);
void		ft_on_arrowr_keypressed(t_fdf *fdf);
void		ft_on_arrowt_keypressed(t_fdf *fdf);
void		ft_on_arrowd_keypressed(t_fdf *fdf);
void		ft_on_plus_keypressed(t_fdf *fdf);
void		ft_on_minus_keypressed(t_fdf *fdf);

t_img		ft_create_empty_img(t_fdf fdf);
t_img		ft_get_null_img(void);
void		ft_create_new_fdf_img(t_fdf *fdf);
void		ft_set_future_fdf_img(t_fdf *fdf, t_img img);
void		ft_set_new_img_to_screen(t_fdf *fdf);

void		ft_init_fdf_draw_helpers(t_fdf *fdf);
void		ft_update_zoom(t_fdf *fdf, int zoom);

void		ft_put_pixel_on_img(t_fdf *fdf, int x, int y, int color);
void		ft_draw_line(t_fdf *fdf, t_2dpt p1, t_2dpt p2);

t_2dpt		pt2d_from_pt3d(t_fdf *fdf, t_3dpt pt3d);

#endif