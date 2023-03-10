/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:37:41 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/03/02 17:20:00 by jzaldiva         ###   ########.fr       */
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


// Function to color the all the points in the map.
// The color is based on the height of the point. The closer to the max z, the
// closer to the max color. The closer to the min z, the closer to the min color.
void	ft_color_map(t_map *map)
{
	int		i;
	int		j;
	int		color;
	double	percent;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			percent = (double)(map->points[i][j].z - map->min_z) / (double)(map->max_z - map->min_z);
			color = (int)((1 - percent) * map->min_color + percent * map->max_color);
			map->points[i][j].color = color;
			j++;
		}
		i++;
	}
}


// Fucntion to read the .fdf file.
// Each digit is a point in the map. The points are separated by spaces.
// The function returns a map structure.
t_map	ft_read_map(char *file)
{
	int		i;
	int		j;
	int		fd;
	int		tmp;
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
	// Assign color to the min and max z.
	map.min_color = MIN_COLOR;
	map.max_color = MAX_COLOR;

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

	map.max_z = 0;
	map.min_z = 0;

	// Read the file again.
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (j < map.width)
		{
			tmp = ft_atoi(line);
			map.points[i][j].x = j;
			map.points[i][j].y = i;
			map.points[i][j].z = tmp;
			if (tmp > map.max_z)
				map.max_z = tmp;
			if (tmp < map.min_z)
				map.min_z = tmp;
			while (*line != ' ' && *line)
				line++;
			while (*line == ' ' && *line)
				line++;
			j++;
		}
		// ft_printf("line: %s\n", line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	// Close the file.
	fd = close(fd);
	if (fd == -1)
		return (ft_free_map(map));

	ft_color_map(&map);
	return (map);
}


// Function to escalate the map. The map is escalated depending the width and height of the window.
// The map is escalated so that it fits in the window. It has to take into acount the isometric projection.
// SOOOOOOOOOOOOOOOOOOSSSSSSSSSSS
void	ft_escalate_map(t_map *map)
{
	int		i;
	int		j;
	double	x_center;
	double	y_center;
	double	x_max;
	double	y_max;
	double	x_min;
	double	y_min;
	double	x_escalate;
	double	y_escalate;

	// Get the center of the map. For the isometric projection, the center is the center of the x and y axis.
	x_center = 0;
	y_center = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			x_center += map->points[i][j].x;
			y_center += map->points[i][j].y;
			j++;
		}
		i++;
	}
	x_center /= map->height * map->width;
	y_center /= map->height * map->width;
	// Get the max and min x and y.
	x_max = 0;
	y_max = 0;
	x_min = 0;
	y_min = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->points[i][j].x > x_max)
				x_max = map->points[i][j].x;
			if (map->points[i][j].x < x_min)
				x_min = map->points[i][j].x;
			if (map->points[i][j].y > y_max)
				y_max = map->points[i][j].y;
			if (map->points[i][j].y < y_min)
				y_min = map->points[i][j].y;
			j++;
		}
		i++;
	}
	// Get the escalates.
	x_escalate = (double)WIN_WIDTH / (x_max - x_min) + 25;
	y_escalate = (double)WIN_HEIGHT / (y_max - y_min) + 25;
	// Escalate the map.
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x = (map->points[i][j].x - x_center) * x_escalate + x_center;
			map->points[i][j].y = (map->points[i][j].y - y_center) * y_escalate + y_center;
			j++;
		}
		i++;
	}
}


// Function to move the map, so that the center of the map is in the center of the window.
void	ft_move_map(t_map *map, int x, int y)
{
	int		i;
	int		j;
	double	x_center;
	double	y_center;

	// Get the center of the map.
	x_center = 0;
	y_center = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			x_center += map->points[i][j].x;
			y_center += map->points[i][j].y;
			j++;
		}
		i++;
	}
	x_center /= map->height * map->width;
	y_center /= map->height * map->width;
	// Move the map.
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x += x - x_center;
			map->points[i][j].y += y - y_center;
			j++;
		}
		i++;
	}
}


// Function to set an isometric projection to the map.
void	ft_iso_map(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_iso(mlx, &map->points[i][j]);
			j++;
		}
		i++;
	}
}

// Function to draw the map. First, escalates the map to fit the window.
// Then, draws the map.
void	ft_draw_map(t_mlx *mlx, t_map map)
{
	int	i;
	int	j;

	// Set the isometric projection.
	ft_iso_map(mlx, &map);
	// Move the map.
	ft_move_map(&map, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	// // // Escalate the map.
	ft_escalate_map(&map);


	// Draw the map.
	i = 0;
	int b = 1;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			// if (b)
			// {
			// 	ft_draw_line(mlx, map.points[i][j], map.points[i][j + 1]);
			// 	b = 0;
			// }
			// Connect the point with the four points around it. (if they exist)
			if (i < map.height - 1)
				ft_draw_line(mlx, map.points[i][j], map.points[i + 1][j]);
			if (j < map.width - 1)
				ft_draw_line(mlx, map.points[i][j], map.points[i][j + 1]);
			// mlx_pixel_put(mlx->mlx, mlx->win, map.points[i][j].x, map.points[i][j].y, map.points[i][j].color);
			j++;
		}
		i++;
	}

	ft_printf("Map drawn.\n");
	// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}