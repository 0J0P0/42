/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:08:25 by mperez-a          #+#    #+#             */
/*   Updated: 2023/01/19 21:23:55 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*read_file(int fd, char *str_file)
{
	int		bytes;
	char	*buffer;

	bytes = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (ft_free(&str_file));
	while (!ft_strchr(str_file, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (ft_free(&str_file));
		}
		buffer[bytes] = '\0';
		str_file = ft_strjoin(str_file, buffer);
	}
	free(buffer);
	return (str_file);
}

char	*read_line(char *str_file)
{
	int		i;
	char	*str;

	i = 0;
	if (str_file[i] == '\0')
		return (NULL);
	while (str_file[i] && str_file[i] != '\n')
		i++;
	if (str_file[i] != '\n')
		str = (char *)malloc(sizeof(char) * i + 1);
	else
		str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (str_file[i] && str_file[i] != '\n')
	{
		str[i] = str_file[i];
		i++;
	}
	if (str_file[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*read_left(char *str_file)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (str_file[i] && str_file[i] != '\n')
		i++;
	if (str_file[i] == '\0')
		return (ft_free(&str_file));
	str = (char *)malloc(sizeof(char) * (ft_strlen(str_file) - i + 1));
	if (!str)
		return (ft_free(&str_file));
	i++;
	while (str_file[i])
		str[j++] = str_file[i++];
	if (j > 0)
		str[j] = '\0';
	else
	{
		free(str);
		return (ft_free(&str_file));
	}
	ft_free(&str_file);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str_file[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_file[fd] = read_file(fd, str_file[fd]);
	if (!str_file[fd])
		return (NULL);
	line = read_line(str_file[fd]);
	if (!line)
		return (ft_free(&str_file[fd]));
	str_file[fd] = read_left(str_file[fd]);
	return (line);
}
