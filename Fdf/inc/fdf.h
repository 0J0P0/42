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
/* ******************************** STRUCTURES ******************************** */
typedef struct	s_point
{
    int			x;
    int			y;
    int			z;
    int			color;
}				t_point;

typedef struct	s_map
{
    t_point		**points;
    int			width;
    int			height;
    int         max_z;
    int         min_z;
}				t_map;

typedef struct	s_mlx
{
    void		*mlx;
    void		*win;
    t_map		*map;
}				t_mlx;

/* ******************************** PROTOTYPES ******************************** */
void	ft_error(int err_code, int ex_code);

int		ft_count_points(char *line, char c);

int		ft_count_words(char *line, char c);

int		ft_check_line(char *line);

int		ft_check_file(char *file);

t_map	read_map(char *file);

t_map	ft_free_map(t_map map);

# endif
