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

#include "fdf.h"

// Programm to create a wireframe model of a relief landscape.
// A map is passed as a parameter to the program.
// The map is a file containing a list of (x, y, z) coordinates, separated by spaces.
// x and y are the coordinates of the point in the plan, and z its altitude.
int	main(int argc, char argv*)
{
	// Check if the number of parameters is correct.
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf map.fdf");
		return (0);
	}
	// Check if the file is valid.

}