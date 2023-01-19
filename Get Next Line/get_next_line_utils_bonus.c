/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:10:44 by mperez-a          #+#    #+#             */
/*   Updated: 2022/11/15 17:40:41 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *str_file, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!str_file)
	{
		str_file = (char *)malloc(1 * sizeof(char));
		if (!str_file)
			return (NULL);
		str_file[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(str_file) + ft_strlen(buff)) + 1));
	if (!str)
		return (ft_free(&str_file));
	i = -1;
	j = 0;
	if (str_file)
		while (str_file[++i] != '\0')
			str[i] = str_file[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[i] = '\0';
	free(str_file);
	return (str);
}
