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

// Programm to create a wireframe model of a relief landscape.
// A map is passed as a parameter to the program.
// The map is a file containing a list of (x, y, z) coordinates, separated by spaces.
// x and y are the coordinates of the point in the plan, and z its altitude.
int	main(int argc, char* argv[])
{
	t_map	map;

	// Check if the number of parameters is correct.
	if (argc != 2)
		ft_error(ERR_ARG, 1);
	// Check if the file is valid.
	if (!ft_check_file(argv[1]))
		ft_error(ERR_INV, 1);
	
	// ////////////////////////////////////////////////////////////////////
	void	*mlx;
	void	*win;
	// Initialize connection to the graphic system.
	mlx = mlx_init();
	// Create a new window.
	win = mlx_new_window(mlx, 1920, 1080, "Fdf");
	mlx_loop(mlx);
	// ////////////////////////////////////////////////////////////////////
	// // Read the file.
	// map = read_map(argv[1]);
	// return (0);
}