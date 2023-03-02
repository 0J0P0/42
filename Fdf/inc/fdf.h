/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:58:42 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/01/29 15:58:42 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// after a coment in the .h, make file doesnt notice

#ifndef FDF_H
# define FDF_H

/* ******************************** INCLUDES ******************************** */
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../lib/Libft/libft.h"
# include "../lib/Printf/inc/ft_printf.h"
# include "../lib/Mlx/minilibx_macos/mlx.h"

/* ******************************** DEFINES ******************************** */
# define ERR_ARG	(int)1
# define ERR_MC		(int)2
# define ERR_CNF	(int)3
# define ERR_PERM	(int)4
# define ERR_NFD	(int)5
# define ERR_FD		(int)6
# define ERR_PERR	(int)7
# define ERR_INV	(int)8
# define ERR_MLX	(int)9

// Define the width and height of the window.
# define WIN_WIDTH	(int)1080
# define WIN_HEIGHT	(int)1080

// Define the color of the min and max points in the map.
# define MIN_COLOR	(int)0xFFFFFF
# define MAX_COLOR	(int)0xFF0000  // red
/* ******************************** STRUCTURES ******************************** */
typedef struct	s_point
{
	double			x;
	double			y;
	int				z;
	int				color;
}				t_point;

// Struct of a map, containing the matrix of points, the width and height of the map, and the min and max points in terms of z with its color.
typedef struct	s_map
{
	t_point		**points;
	int			width;
	int			height;
	int			min_z;
	int			max_z;
	int			min_color;
	int			max_color;
}				t_map;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
	double		angle;
}				t_mlx;

/* ******************************** PROTOTYPES ******************************** */
void	ft_error(int err_code, int ex_code);

int		ft_check_file(char *file);

int		ft_check_line(char *line);
/* ******************************** MAP ******************************** */

t_map	ft_free_map(t_map map);

t_map	ft_read_map(char *file);

char	*get_next_line(int fd);


/* ******************************** DRAW ******************************** */
void	ft_draw_line(t_mlx *mlx, t_point p1, t_point p2);

void	ft_mlx_init(t_mlx *mlx);

void	ft_draw_map(t_mlx *mlx, t_map map);

void	ft_iso(t_mlx *mlx, t_point *point);

# endif
