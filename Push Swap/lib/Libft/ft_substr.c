/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:57:53 by jzaldiva          #+#    #+#             */
/*   Updated: 2022/10/04 17:36:37 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s || !len || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (i < len)
		substr[i++] = s[start++];
	return (substr);
}

// int main()
// {
// 	printf("%s\n", ft_substr("hola", 2, 1));
// }