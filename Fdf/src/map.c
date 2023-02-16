/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:37:41 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/16 18:05:38 by jzaldiva         ###   ########.fr       */
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
		map.points[i] = NULL;
		i++;
	}
	free(map.points);
	return (map);
}


// Function to count the number of points in a line.
int	ft_count_points(char *line, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] != c)
			count++;
		while (line[i] != c && line[i])
			i++;
		while (line[i] == c && line[i])
			i++;
	}
	return (count);
}


// Fucntion to read the .fdf file.
// Each digit is a point in the map. The points are separated by spaces.
// The function returns a map structure.
t_map	ft_read_map(char *file)
{
	int		i;
	int		j;
	int		fd;
	int 	tmp;
	t_map	map;
	char	*line;

	// Open the file.
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(ERR_NFD, 1);
	// Read the first line of the file.
	line = get_next_line(fd);
	if (!line)
		ft_error(ERR_NFD, 1);
	// Get the width of the map.
	map.width = ft_count_points(line, ' ');
	// Get the height of the map.
	map.height = 1;
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		map.height++;
		free(line);
		line = get_next_line(fd);		
	}
	free(line);
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

	// Read the file again.
	map.max_z = 0;
	map.min_z = 0;
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (j < map.width)
		{
			// Get the x coordinate.
			map.points[i][j].x = i;
			// Get the y coordinate.
			map.points[i][j].y = j;
			// Get the z coordinate.
			tmp = ft_atoi(line);
			if (tmp > map.max_z)
				map.max_z = tmp;
			if (tmp < map.min_z)
				map.min_z = tmp;
			map.points[i][j].z = tmp;
			// Get the color.
			map.points[i][j].color = 0xFFFFFF;
			// Move to the next point.
			line = ft_strchr(line, ' ');
			line++;
			j++;
		}
		i++;
		line = get_next_line(fd);
	}
	free(line);
	// Close the file.
	fd = close(fd);
	if (fd == -1)
		return (ft_free_map(map));
	return (map);
}
