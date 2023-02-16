/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:14:43 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/16 19:46:27 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// Function to compute the number of steps to draw a line.
// Parameters:
// - start point.
// - end point.
int	ft_steps(t_point start, t_point end)
{
	int	dx;
	int	dy;

	// Compute the number of steps.
	dx = abs(end.x - start.x);
	dy = abs(end.y - start.y);
	// Return the maximum number of steps.
	return (dx > dy ? dx : dy);
}

// Function to compute the color of a point in the line, so that the line
// is drawn with a gradient from the start point to the end point.
// Parameters:
// - start point.
// - end point.
// - number of steps.
// Return the color in hexadecimal.
int	ft_color(t_point start, t_point end, int steps)
{
	int	red;
	int	green;
	int	blue;

	// Compute the color of the point.
	// The color is computed by adding the color of the start point
	// and the color of the end point, and then dividing the result
	// by the number of steps.

	// The color is composed of 3 bytes: red, green and blue.

	// The color is shifted 16 bits to the right to get the red byte.
	red = (start.color >> 16) + (end.color >> 16) * steps / ft_steps(start, end);
	// The color is shifted 8 bits to the right to get the green byte.
	green = (start.color >> 8) + (end.color >> 8) * steps / ft_steps(start, end);
	// The color is not shifted to get the blue byte.
	blue = (start.color) + (end.color) * steps / ft_steps(start, end);
	// Return the color. The color is composed of 3 bytes. The red byte
	// is shifted 16 bits to the left, the green byte is shifted 8 bits
	// to the left, and the blue byte is not shifted.
	return (red << 16 | green << 8 | blue);
}

// Function to draw a line.
// Parameters:
// - mlx structure.
// - start point.
// - end point.
void	ft_draw_line(t_mlx *mlx, t_point start, t_point end)
{
	int		steps;
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;

	steps = ft_steps(start, end);
	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;
	x = start.x;
	y = start.y;
	while (steps--)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, ft_color(start, end, steps));
		x += x_inc;
		y += y_inc;
	}
}
