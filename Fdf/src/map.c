/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:37:41 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/14 15:53:28 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// Function to free the map.
t_map	ft_free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		free(map.points[i]);
		i++;
	}
	free(map.points);
	return (map);
}

// Fucntion to read the .fdf file.
// Each digit is a point in the map. The points are separated by spaces.
// The function returns a map structure.
t_map	read_map(char *file)
{
	int		i;
	int		j;
	int		fd;
	t_map	map;
	char	*line;

	// Open the file.
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(ERR_NFD, 1);
	// Read the first line of the file.
	get_next_line(fd, &line);
	// Get the width of the map.
	map.width = ft_count_points(line, ' ');
	// Get the height of the map.
	map.height = 1;
	while (get_next_line(fd, &line))
		map.height++;
	// Allocate memory for the map.
	map.points = (t_point **)malloc(sizeof(t_point *) * map.height);
	if (!map.points)
		ft_error(ERR_MC, 1);
	i = 0;
	while (i < map.height)
	{
		map.points[i] = (t_point *)malloc(sizeof(t_point) * map.width);
		if (!map.points[i])
			ft_error(ERR_MC, 1);
		i++;
	}
	// Close the file.
	fd = close(fd);
	if (fd == -1)
		return (ft_free_map(map));
	// Open the file again.
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_free_map(map));
	i = 0;
	while (get_next_line(fd, &line))
	{
		j = 0;
		while (j < map.width)
		{
			// Get the x coordinate.
			map.points[i][j].x = j;
			// Get the y coordinate.
			map.points[i][j].y = i;
			// Get the z coordinate.
			map.points[i][j].z = ft_atoi(line);
			// Get the color.
			map.points[i][j].color = 0xFFFFFF;
			// Move to the next point.
			line = ft_strchr(line, ' ');
			line++;
			j++;
		}
		i++;
	}
	// Close the file.
	fd = close(fd);
	if (fd == -1)
		return (ft_free_map(map));
	return (map);
}