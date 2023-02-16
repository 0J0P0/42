/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:14:43 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/16 17:45:01 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// Function to draw a line.
// Parameters:
// - mlx structure.
// - start point.
// - end point.
// void	ft_draw_line(t_mlx *mlx, t_point start, t_point end)
// {
// 	int		dx;
// 	int		dy;
// 	int		steps;
// 	float	x_inc;
// 	float	y_inc;
// 	float	x;
// 	float	y;

// 	// Calculate the distance between the start and end points.
// 	dx = end.x - start.x;
// 	dy = end.y - start.y;
// 	// Calculate the number of steps to draw the line.
// 	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
// 	x_inc = dx / (float)steps;
// 	y_inc = dy / (float)steps;
// 	x = start.x;
// 	y = start.y;
// 	while (steps--)
// 	{
// 		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFFFF);
// 		x += x_inc;
// 		y += y_inc;
// 	}
// }
