/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:59:32 by jzaldiva          #+#    #+#             */
/*   Updated: 2022/09/16 16:59:33 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	tmp;

	i = 0;
	size = ft_strlen(str);
	i = 0;
	while (i < (size / 2))
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i++;
	}
	return (str);
}

static int	ft_intlen(const int n)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = n;
	while (tmp)
	{
		tmp /= 10;
		++i;
	}
	return (i);
}

static char	*ft_fill_num(int n, int i, int sign, char *num)
{
	while (n)
	{
		num[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		num[i] = '-';
	return (num);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		size;
	char	*num;

	sign = 0;
	size = ft_intlen(n) + 1;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n *= (-1);
		sign = 1;
		++size;
	}
	num = (char *)ft_calloc(sizeof(char), (size));
	if (!num)
		return (NULL);
	ft_fill_num(n, 0, sign, num);
	return (ft_strrev(num));
}
