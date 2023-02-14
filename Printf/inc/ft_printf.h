/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:00:31 by jzaldiva          #+#    #+#             */
/*   Updated: 2022/10/21 17:00:31 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/**			INCLUDES		**/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/**		PRINTF FUNCTION		**/

typedef unsigned long int	t_uli;

int	ft_printf(char const *str, ...);

/**	PRINTF EXTRA FUNCTIONS  **/

int	ft_putchar_len(char c);

int	ft_putstr_len(char *s);

int	ft_putnbr_len(long n);

int	ft_putunbr_len(unsigned long int nbr, char *base);

#endif