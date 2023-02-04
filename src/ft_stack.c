/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:50:42 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/03 15:50:42 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/push_swap.h"

// Free a stack.
void	*ft_free_stack(t_stack *stack)
{
    t_node *node;

	if (!stack) // If the stack is empty, do nothing.
		return (NULL);
    node = stack->top;
    while (node)
    {
        stack->top = node->next;
        free(node);
		node = NULL;
        node = stack->top;
    }
    free(stack);
	stack = NULL;
	return (NULL);
}

// Print a stack.
void	ft_print_stack(t_stack *stack)
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

// Push a node to the top of the stack.
// ...

// Check if the stack is sorted in ascending order.
int		ft_is_sorted(t_stack *stack)
{
    t_node	*node;

    if (!stack)
        return (0);
    node = stack->top;
    while (node->next)
    {
        if (node->value > node->next->value)
            return (0);
        node = node->next;
    }
    return (1);
}

// Initialize a node.
t_node  *ft_init_node(int index, int value)
{
    t_node  *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->index = index;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

// Initialize a stack.
t_stack	*ft_init_stack(int argc, char *argv[], char id)
{
	int		i;
	t_node	*node;
	t_stack	*stack;

	// Allocate memory for the stack.
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	// Initialize the stack.
	stack->id = id;
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	// If the stack is empty, return the stack.
	if (argc == 0)
		return (stack);
	// Create the first node.
    node = ft_init_node(0, ft_atoi(argv[1]));
	if (!node)
        return (ft_free_stack(stack));
	// Add the node to the stack.
	stack->top = node;
	stack->bottom = node;
	stack->size++;
	// Create the rest of the nodes.
	i = 2;
	while (i < argc)
	{
		// Create the node.
        node = ft_init_node(i - 1, ft_atoi(argv[i]));
        if (!node)
            return (ft_free_stack(stack));
		// Add the node to the stack.
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->bottom = node;
		stack->size++;
		i++;
	}
	return (stack);
}