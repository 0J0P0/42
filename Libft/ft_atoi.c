/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:29:28 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/14 14:29:28 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		++i;
	if (nptr[i] == '+')
		++i;
	else if (nptr[i] == '-')
	{
		sign = -1;
		++i;
	}
	n = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		n = 10 * n + (nptr[i] - '0');
		++i;
	}
	return (sign * n);
}
