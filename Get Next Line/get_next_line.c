/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:50:46 by eralonso          #+#    #+#             */
/*   Updated: 2022/11/10 13:17:08 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

void	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
		str = NULL;
		return (NULL);
	}
	return (NULL);
}

void	ft_read_file(t_data *data)
{
	int	bytes;

	data->line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!data->line)
		data->err = !ft_free(&(data->buffer));
	bytes = 1;
	while (!data->err && bytes && !ft_strchr(data->buffer, '\n'))
	{
		bytes = read(data->fd, data->line, BUFFER_SIZE);
		if (bytes == -1)
			data->err = !ft_free(&(data->buffer));
		else
		{
			if (*data->line || data->buffer)
			{
				data->line[bytes] = '\0';
				data->buffer = ft_strjoin(data->buffer, data->line);
				if (!data->buffer)
					data->err = 1;
			}
		}
	}
	ft_free(&(data->line));
}

void	ft_get_line(t_data *data)
{
	int	len;

	if (!*data->buffer)
	{
		data->line = NULL;
		return ;
	}
	len = 0;
	while (data->buffer[len] && data->buffer[len] != '\n')
		len++;
	data->line = ft_substr(data->buffer, 0, len + 1);
	if (!data->line)
		data->err = 1;
}

void	ft_clean_buffer(t_data *data)
{
	char	*aux;
	int		start;

	start = 0;
	while (data->buffer[start] && data->buffer[start] != '\n')
		start++;
	aux = ft_strdup(data->buffer);
	if (!aux)
	{
		data->err = !ft_free(&(data->buffer));
		return ;
	}
	ft_free(&(data->buffer));
	data->buffer = ft_substr(aux, start + 1, (ft_strlen(aux) - start));
	if (!data->buffer)
		data->err = 1;
	ft_free(&aux);
}

char	*get_next_line(int fd)
{
	static t_data	data;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!data.buffer)
	{
		data.buffer = ft_strdup("");
		if (!data.buffer)
			return (NULL);
	}
	data.fd = fd;
	data.err = 0;
	if (!data.err)
		ft_read_file(&data);
	if (!data.err)
		ft_get_line(&data);
	if (!data.err)
		ft_clean_buffer(&data);
	if (data.err || !ft_strchr(data.line, '\n'))
		ft_free(&(data.buffer));
	return (data.line);
}
