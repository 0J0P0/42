/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:01:26 by jzaldiva          #+#    #+#             */
/*   Updated: 2022/10/21 17:01:26 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/ft_printf.h"

/**     FT_PUTUNBR_LEN      **/

int	ft_putchar_len(char c)
{
	return (write(1, &c, 1));
}

/**     FT_PUTSTR_LEN      **/

int	ft_putstr_len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		if (ft_putchar_len(s[i]) == -1)
			return (-1);
		++i;
	}
	return (i);
}

/**     FT_PUTNBR_LEN      **/

int	ft_putnbr_len(long n)
{
	long	len;

	len = 0;
	if (n < 0)
	{
		if (ft_putchar_len('-') == -1)
			return (-1);
		len = ft_putnbr_len(n * (-1));
		if (len != -1)
			len++;
	}
	else if (n < 10)
		len = ft_putchar_len((char)(n + '0'));
	else
	{
		len = ft_putnbr_len(n / 10);
		if (len != -1)
		{
			if (ft_putchar_len((n % 10) + '0') == -1)
				return (-1);
			len++;
		}
	}
	return (len);
}

/**     FT_PUTUNBR_LEN      **/

static int	ft_strlen_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	ft_putunbr_len(unsigned long int nbr, char *base)
{
	int					len;
	unsigned long int	lenbase;

	len = 0;
	lenbase = ft_strlen_len(base);
	if (nbr >= lenbase)
	{
		len = ft_putunbr_len(nbr / lenbase, base);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar_len(base[nbr % lenbase]) == -1)
		return (-1);
	++len;
	return (len);
}
