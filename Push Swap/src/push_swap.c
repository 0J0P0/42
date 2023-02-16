/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:03:23 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/01/30 03:03:23 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	// Create two stacks.
	t_stack	*stack_a;
	t_stack	*stack_b;

	// Check if the parameters are valid.
	if (!ft_valid_parameters(argc, argv))
		ft_error();

	// Initialize the stacks. Stack a contains the numbers as parameters. Stack b is empty.
	stack_a = ft_init_stack(argc, argv, 'a');
	if (!stack_a)
		ft_error();
	stack_b = ft_init_stack(0, NULL, 'b');
	if (!stack_b)
		ft_error();
	// Sort the stack a, using stack b. Pass the stacks as references.
	ft_sort_stack(stack_a, stack_b);

	// // Print the stacks.
	// ft_print_stack(stack_a);
	// ft_print_stack(stack_b);
	// Free the stacks.
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}