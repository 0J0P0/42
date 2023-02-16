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

// // Function to create a point.
// t_point	ft_new_point(int x, int y, int z)
// {
// 	t_point	point;

// 	point.x = x;
// 	point.y = y;
// 	point.z = z;
// 	return (point);
// }


// Programm to create a wireframe model of a relief landscape.
// A map is passed as a parameter to the program.
// The map is a file containing a list of (x, y, z) coordinates, separated by spaces.
// x and y are the coordinates of the point in the plan, and z its altitude.
int	main(int argc, char* argv[])
{
	t_map	map;
	// t_mlx	mlx;

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
	// mlx.mlx = mlx_init();
	// if (!mlx.mlx)
	// 	ft_error(ERR_MLX, 1);
	// mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "Fdf");
	// if (!mlx.win)
	// 	ft_error(ERR_MLX, 1);
 	

	// Draw a line splitting the map in two.
	// ft_draw_line(&mlx, ft_new_point(0, 500, 0), ft_new_point(1000, 500, 0));

	// Print the map data.
	ft_printf("----------------------------------\n");
	ft_printf("Map data: %d x %d\n", map.width, map.height);
	// Print min and max z
	ft_printf("Min z: %d\n", map.min_z);
	ft_printf("Max z: %d\n", map.max_z);
	// Print all the points. As (x, y, z).
	for (int i = 0; i < map.height; i++)
	{
		for (int j = 0; j < map.width; j++)
		{
			ft_printf("(%d) ", map.points[i][j].z);
		}
		ft_printf("\n");
	}
	ft_printf("----------------------------------\n");


	// mlx_loop(mlx.mlx);
	ft_printf("Tot be\n");
	map = ft_free_map(map);
	return (0);
}