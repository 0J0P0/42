/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:06:16 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/16 20:06:16 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

// Function to set an isometric projection.
void	ft_iso(t_mlx *mlx, t_point *point)
{
	int	x;
	int	y;

	// Set an isometric projection.
	x = point->x;
	y = point->y;
	point->x = (x - y) * cos(mlx->angle);
	point->y = (x + y) * sin(mlx->angle) - point->z;
}