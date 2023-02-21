/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:37:41 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/21 16:28:44 by jzaldiva         ###   ########.fr       */
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
			map.points[i][j].x = j;
			// Get the y coordinate.
			map.points[i][j].y = i;
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

	ft_color_map(&map);
	return (map);
}


// Fucntion to escalate the map. The map is scaled to fit the window in an isometric
// projection.
void	ft_escalate_map(t_map *map)
{
	int		i;
	int		j;
	double	scale;

	// Get the scale.
	scale = (double)WIN_WIDTH / (double)map->width;
	if (scale > (double)WIN_HEIGHT / (double)map->height)
		scale = (double)WIN_HEIGHT / (double)map->height;
	// Escalate the map.
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->points[i][j].x *= scale;
			map->points[i][j].y *= scale;
			map->points[i][j].z *= scale;
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
			ft_iso(mlx, &map->points[i][j], &map->points[i][j]);
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

	// // Set an isometric projection.
	// ft_iso_map(mlx, &map);
	// Escalate the map.
	ft_escalate_map(&map);
	// Move the map to the center of the window.
	ft_move_map(&map, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	ft_printf("max_z = %d\n", map.max_z);
	// Draw the map.
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (j < map.width - 1)
				ft_draw_line(mlx, map.points[i][j], map.points[i][j + 1]);
			if (i < map.height - 1)
				ft_draw_line(mlx, map.points[i][j], map.points[i + 1][j]);
			j++;
		}
		i++;
	}
	ft_printf("Map drawn.\n");
	// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}