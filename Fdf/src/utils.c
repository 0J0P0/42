/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:34:25 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/14 15:56:27 by jzaldiva         ###   ########.fr       */
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

// Function to count the number of points in a line. Each point is separated by
// a space.
int		ft_count_points(char *line, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] != c)  // If the character is not a space, it is a point.
			count++;
		while (line[i] && line[i] != c)  // Skip the characters that are not spaces.
			i++;
		if (line[i])  // If the character is a space, skip it.
			i++;
	}
	return (count);
}

// Function to count the number of words in a line. Each word is separated by
// a space.
int		ft_count_words(char *line, char c)
{
    int	i;
    int	count;

    i = 0;
    count = 0;
    while (line[i])
    {
        while (line[i] && line[i] == c)  // Skip the spaces.
            i++;
        if (line[i])  // If the character is not a space, it is a word.
            count++;
        while (line[i] && line[i] != c)  // Skip the characters that are not spaces.
            i++;
    }
    return (count);
}

// Function to check if the line is valid.
int		ft_check_line(char *line)
{
    int	i;

    i = 0;
    while (line[i])
    {
        // If the character is not a space or a digit, the line is invalid.
        if (line[i] != ' ' && (line[i] < '0' || line[i] > '9'))
            return (0);
        i++;
    }
    return (1);
}

// Function to check if the file is valid.
int		ft_check_file(char *file)
{
	int		fd;
	char	*line;

	// Open the file.
	fd = open(file, O_RDONLY);
	// Check if the file can be opened.
	if (fd == -1)
		return (0);
	// Read the first line of the file.
	get_next_line(fd, &line);
	// Check if the first line is valid.
	if (ft_check_line(line) == 0)
		return (0);
	// Read the rest of the file.
	while (get_next_line(fd, &line) > 0)
	{
		// Check if the line is valid.
		if (ft_check_line(line) == 0)
			return (0);
		// Check if the line has the same number of coordinates as the first line.
		if (ft_count_words(line, ' ') != ft_count_words(line, ' '))
			return (0);
	}
	// Close the file.
	fd = close(fd);
    if (fd == -1)
        return (0);
	return (1);
}