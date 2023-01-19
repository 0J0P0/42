/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:51:28 by eralonso          #+#    #+#             */
/*   Updated: 2022/11/10 11:41:26 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		str_len;
	int		i;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * str_len + 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (str[++i] && i < str_len)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (ft_free(&s1));
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	ft_free(&s1);
	return (str);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int		i;

	if (!s)
		return (NULL);
	if ((len + start) > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		sub[i] = s[start++];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
