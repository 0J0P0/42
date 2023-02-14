/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:59:37 by jzaldiva          #+#    #+#             */
/*   Updated: 2022/10/21 16:59:37 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/ft_printf.h"

int	ft_print_arg(char c, va_list ptr)
{
	int	aux;

	if (c == 'c')
		return (ft_putchar_len(va_arg(ptr, int)));
	if (c == 's')
		return (ft_putstr_len(va_arg(ptr, char *)));
	if (c == 'p')
	{
		if (ft_putstr_len("0x") == -1)
			return (-1);
		aux = ft_putunbr_len(va_arg(ptr, t_uli), "0123456789abcdef");
		if (aux != -1)
			return (aux + 2);
	}
	if (c == 'd' || c == 'i')
		return (ft_putnbr_len(va_arg(ptr, int)));
	if (c == 'u')
		return (ft_putunbr_len(va_arg(ptr, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_putunbr_len(va_arg(ptr, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putunbr_len(va_arg(ptr, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar_len('%'));
	return (-1);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	int		aux;
	va_list	ptr;

	i = 0;
	len = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
			aux = ft_print_arg(str[++i], ptr);
		else
			aux = ft_putchar_len(str[i]);
		if (aux == -1)
			return (-1);
		len += aux;
		++i;
	}
	va_end(ptr);
	return (len);
}
