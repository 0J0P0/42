/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:34:25 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/16 18:05:43 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// Error function that prints the error message and exits the program with the
// corresponding error code.
void	ft_error(int err_code, int ex_code)
{
	if (err_code == ERR_ARG)
		ft_printf("Error: Wrong number of arguments.\n");
	else if (err_code == ERR_MC)
		ft_printf("Error: Memory allocation failed.\n");
	else if (err_code == ERR_CNF)
		ft_printf("Error: Command not found.\n");
	else if (err_code == ERR_PERM)
		ft_printf("Error: Permission denied.\n");
	else if (err_code == ERR_NFD)
		ft_printf("Error: No such file or directory.\n");
	else if (err_code == ERR_FD)
		ft_printf("Error: File descriptor error.\n");
    else if (err_code == ERR_INV)
        ft_printf("Error: Invalid file.\n");
    else if (err_code == ERR_MLX)
        ft_printf("Error: Mlx error.\n");
	else if (err_code == ERR_PERR)
		perror("Error: ");
	exit(ex_code);
}

// Function to count the number of coordinates in a line.
int		ft_count_coord(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		// If the character is not a space and the next character is a space or
		// the end of the string, increase the count.
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

// Function to check if the line is valid. It can only contain numbers and
// spaces.
int		ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			// If the character is not a number, return 0.
			if (line[i] < '0' || line[i] > '9')
				return (0);
		i++;
	}
	return (1);
}

// Function to check if the file is valid.
int		ft_check_file(char *file)
{
	int		fd;
	int		count;
	char	*line;

	// Open the file.
	fd = open(file, O_RDONLY);
	// Check if the file can be opened.
	if (fd == -1)
		return (0);
	// Read the first line of the file.
	line = get_next_line(fd);
	if (!line)
		return (0);
	// Check if the line is valid.
	if (!ft_check_line(line))
		return (0);
	// Count number of coordinates in the line.
	count = ft_count_coord(line, ' ');
	// Free the line.
	free(line);
	// Read the rest of the file.
	line = get_next_line(fd);
	while (line)
	{
		// Check if the line is valid.
		if (!ft_check_line(line))
			return (0);
		// Check if the number of coordinates in the line is the same as the
		// first line.
		if (ft_count_coord(line, ' ') != count)
			return (0);
		// Free the line.
		free(line);
		// Read the next line.
		line = get_next_line(fd);
	}
	free(line);
	// Close the file.
	fd = close(fd);
	// Check if the file can be closed.
	if (fd == -1)
		return (0);
	return (1);
}