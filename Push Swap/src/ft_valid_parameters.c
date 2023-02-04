/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:10:42 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/01/31 17:10:42 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Print an error message.
void		ft_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

// If there are not numbers, end the program.
int			ft_isnum(char *argv)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if (!ft_isdigit(argv[j]))
			return (0);
		j++;
	}
	return (1);
}

long long	ft_atoll(const char *nptr)
{
	int			i;
	int			sign;
	long long	n;

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

// If there are repeated numbers, end the program.
int			ft_isdup(int argc, char *argv[], int i)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		if (ft_atoll(argv[i]) == ft_atoll(argv[j]) && i != j)
			return (0);
		j++;
	}
	return (1);
}

// Check if the parameters are valid. If the parameters are valid, return 1. If not, return 0.
int			ft_valid_parameters(int argc, char *argv[])
{
	int	i;
	// If there are no parameters, end the program.
	if (argc == 1)
		exit(0);
	i = 1;
	while (i < argc)
	{
		// If there are numbers bigger than an integer, end the program.
		if (ft_atoll(argv[i]) > INT_MAX || ft_atoll(argv[i]) < INT_MIN)
			return (0);

		// If there are repeated numbers, end the program.
		if (!ft_isdup(argc, argv, i) || !ft_isnum(argv[i]))
			return (0);

		i++;
	}
	return (1);
}