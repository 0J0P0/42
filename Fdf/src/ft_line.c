/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:04:50 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/03/02 17:39:23 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

// Function to compute the number of steps to draw a line.
// Parameters:
// - start point.
// - end point.
double	ft_steps(t_point start, t_point end)
{
	return sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
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
	red = abs((end.color >> 16 & 0xFF) - (start.color >> 16 & 0xFF)) * steps / ft_steps(start, end);
	// The color is shifted 8 bits to the right to get the green byte.
	green = abs((end.color >> 8 & 0xFF) - (start.color >> 8 & 0xFF)) * steps / ft_steps(start, end);
	// The color is not shifted to get the blue byte.
	blue = abs((end.color & 0xFF) - (start.color & 0xFF)) * steps / ft_steps(start, end);
	// Return the color. The color is composed of 3 bytes. The red byte
	// is shifted 16 bits to the left, the green byte is shifted 8 bits
	// to the left, and the blue byte is not shifted.
	return ((red << 16) + (green << 8) + blue);
}


// Function to draw a line.
// Parameters:
// - mlx structure.
// - start point.
// - end point.
void	ft_draw_line(t_mlx *mlx, t_point start, t_point end)
{
	double	steps;
	double	x_inc;
	double	y_inc;
	double	x;
	double	y;

	printf("start: %f, %f, %i\n", start.x, start.y, start.z);
	printf("end: %f, %f, %i\n", end.x, end.y, end.z);
	// Compute the number of steps.
	steps = ft_steps(start, end);
	printf("steps: %f\n", steps);
	// Compute the increment in x and y.
	x_inc = (end.x - start.x) / steps;
	y_inc = (end.y - start.y) / steps;
	// Set the initial point.
	x = start.x;
	y = start.y;
	// Draw the line.
	while (steps > 0)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFFFF);
		x += x_inc;
		y += y_inc;
		--steps;
	}
}
