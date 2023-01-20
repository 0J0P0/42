/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:15:11 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/01/20 09:18:42 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_strchr(char *s, int c)
{
	c = (char)c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (&(*s));
		s++;
	}
	if (c == '\0')
		return (&(*s));
	return (NULL);
}

char	*ft_strjoin(char *file, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!file)
	{
		file = (char *)malloc(1 * sizeof(char));
		if (!file)
			return (NULL);
		file[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(file) + ft_strlen(buff) + 1));
	if (!str)
		return (ft_free(&file));
	i = -1;
	j = 0;
	if (file)
		while (file[++i] != '\0')
			str[i] = file[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(file);
	return (str);
}
