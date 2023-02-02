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

// Free a stack.
void	free_stack(t_stack *stack)
{
    t_node *node;

    node = stack->top;
    while (node)
    {
        stack->top = node->next;
        free(node);
        node = stack->top;
    }
    free(stack);
}

// Print a stack.
void	print_stack(t_stack *stack)
{
    t_node *node;

    node = stack->top;
    while (node)
    {
        ft_printf("%d\n", node->value);
        node = node->next;
    }
	if (stack->size == 0) // If the stack is empty, top and bottom are NULL.
		ft_printf("_\n%c Empty stack.\n", stack->id);
	else
    	ft_printf("_\n%c: %d, top node value: %d, bottom node value: %d\n", stack->id, stack->size, stack->top->value, stack->bottom->value);
    // free(node);
}

// Sort the stack a, using the stack b as a buffer.
void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int j;
	int k;
	int min;
	int size;
	int *array;

	size = stack_a->size;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		ft_error();
	i = 0;
	while (i < size)
	{
		array[i] = stack_a->top->value;
		// ft_rx(stack_a);
		ft_px(stack_b, stack_a);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		min = array[0];
		while (j < size - i)
		{
			if (array[j] < min)
				min = array[j];
			j++;
		}
		k = 0;
		while (k < size - i)
		{
			if (array[k] == min)
			{
				ft_px(stack_b, stack_a);
				array[k] = array[size - i - 1];
				break ;
			}
			ft_rx(stack_a);
			k++;
		}
		i++;
	}
	free(array);
}


// Initialize a stack.
t_stack	*init_stack(int argc, char *argv[], char id)
{
	t_stack	*stack;
	t_node	*node;
	int		i;

	// Allocate memory for the stack.
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		ft_error();
	// Initialize the stack.
	stack->id = id;
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	// If the stack is empty, return the stack.
	if (argc == 0)
		return (stack);
	// Create the first node.
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		ft_error();
	node->index = 0;
	node->value = ft_atoi(argv[1]);
	node->next = NULL;
	node->prev = NULL;
	// Add the node to the stack.
	stack->top = node;
	stack->bottom = node;
	stack->size++;
	// Create the rest of the nodes.
	i = 2;
	while (i < argc)
	{
		// Create the node.
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
			ft_error();
		node->index = i - 1;
		node->value = ft_atoi(argv[i]);
		node->next = NULL;
		node->prev = NULL;
		// Add the node to the stack.
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->bottom = node;
		stack->size++;
		i++;
	}
	return (stack);
}


int	main(int argc, char *argv[])
{
	// Create two stacks.
	t_stack	*stack_a;
	t_stack	*stack_b;

	// Check if the parameters are valid.
	if (!ft_valid_parameters(argc, argv))
		ft_error();

	// Initialize the stacks. Stack a contains the numbers as parameters. Stack b is empty.
	stack_a = init_stack(argc, argv, 'a');
	stack_b = init_stack(0, NULL, 'b');

	// Sort the stack a, using stack b.
	sort_stack(stack_a, stack_b);

	// Print the stacks.
	print_stack(stack_a);
	print_stack(stack_b);

	// Free the stacks.
	free_stack(stack_a);
	free_stack(stack_b);

	return (0);
	}