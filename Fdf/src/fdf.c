/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:54:00 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/01/29 15:54:00 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// Function to create a point.
t_point	ft_new_point(int x, int y, int z, int color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}


// Programm to create a wireframe model of a relief landscape.
// A map is passed as a parameter to the program.
// The map is a file containing a list of (x, y, z) coordinates, separated by spaces.
// x and y are the coordinates of the point in the plan, and z its altitude.
int	main(int argc, char* argv[])
{
	t_map	map;
	t_mlx	mlx;

	// Check if the number of parameters is correct.
	if (argc != 2)
		ft_error(ERR_ARG, 1);
	// Check if the file is valid.
	if (!ft_check_file(argv[1]))
		ft_error(ERR_INV, 1);
	
	// Open the file.
	map = ft_read_map(argv[1]);
	if (!map.points)
		ft_error(ERR_MC, 1);

	// Initialize mlx.
	ft_mlx_init(&mlx);
	ft_printf("mlx initialized\n");

	// Draw the map.
	ft_draw_map(&mlx, map);

	// Wait for the user to close the window.
	mlx_loop(mlx.mlx);

	// Free the map.
	map = ft_free_map(map);
	return (0);
}