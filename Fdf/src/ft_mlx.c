/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:58:42 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/16 19:58:42 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

// Function to initialize mlx.
// Returns a t_mlx structure.
void	ft_mlx_init(t_mlx *mlx)
{

    mlx->mlx = mlx_init();
    if (!mlx->mlx)
	 	ft_error(ERR_MLX, 1);
    mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Fdf");
    if (!mlx->win)
        ft_error(ERR_MLX, 1);

    // Set angle
    mlx->angle = 0.523599; // 30 degrees in radians
    // Set z scale
    // mlx->z_scale = 1;


    mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
    if (!mlx->img)
        ft_error(ERR_MLX, 1);
    mlx->data = (int *)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
    if (!mlx->data)
        ft_error(ERR_MLX, 1);
}