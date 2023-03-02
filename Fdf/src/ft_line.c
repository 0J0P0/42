/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:04:50 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/21 16:37:41 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

// Function to compute the number of steps to draw a line.
// Parameters:
// - start point.
// - end point.
int	ft_steps(t_point start, t_point end)
{
	int	dx;
	int	dy;

	// Compute the number of steps.
	dx = fabs(end.x - start.x);
	dy = fabs(end.y - start.y);
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
	ft_printf("line\n");
	int	steps;
	int	x_inc;
	int	y_inc;
	int	x;
	int	y;

	// Set a isometric projection.
	ft_iso(mlx, &start, &end);

	// Compute the number of steps.
	steps = ft_steps(start, end);
	// Compute the increment in x and y.
	x_inc = (end.x - start.x) / steps;
	y_inc = (end.y - start.y) / steps;
	// Set the initial point.
	x = start.x;
	y = start.y;
	// Draw the line.
	while (steps--)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, ft_color(start, end, steps));
		x += x_inc;
		y += y_inc;
	}
}
