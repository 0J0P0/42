/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:21:50 by jzaldiva          #+#    #+#             */
/*   Updated: 2022/09/16 16:21:59 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*tmp;

	tmp = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tmp[i] = s[i];
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}
