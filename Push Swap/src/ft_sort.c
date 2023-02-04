/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:06:54 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/02/03 16:06:54 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/push_swap.h"

// Sort two elements in the stack a.
void	ft_sort_two(t_stack *stack_a)
{
	t_node	*node;

	node = stack_a->top;
	if (node->value > node->next->value)
		ft_sx(stack_a);
}

// Sort three elements in the stack a.
void	ft_sort_three(t_stack *stack_a)
{
	t_node	*node;

	node = stack_a->top;
	if (node->value > node->next->value && node->value > node->next->next->value)  // If the top node is the biggest.
	{
		if (node->next->value > node->next->next->value) // If the middle node is bigger than the bottom node.
		{
			ft_sx(stack_a);
			ft_rrx(stack_a);
		}
		else  // If the bottom node is bigger than the middle node.
			ft_rx(stack_a);
	}
	else if (node->value < node->next->value && node->value < node->next->next->value)  // If the top node is the smallest.
	{
		// If the middle node is bigger than the bottom node.
		if (node->next->value > node->next->next->value)
		{
			ft_sx(stack_a);
			ft_rx(stack_a);
		}
	}
	else  // If the top node is in the middle.
	{
		// If the top node is bigger than the middle node and smaller than the bottom node.
		if (node->value > node->next->value && node->value < node->next->next->value)
			ft_sx(stack_a);
		// If the top node is smaller than the middle node and bigger than the bottom node.
		else if (node->value < node->next->value && node->value > node->next->next->value)
			ft_rrx(stack_a);
	}
}

// Sort four elements in the stack a. Using the ft_sort_three function and the ft_px function.
void	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	ft_sort_three(stack_a);
	ft_px(stack_b, stack_a);
	ft_sort_three(stack_a);
	ft_px(stack_a, stack_b);
}

// Sort the stack a, using the stack b as a buffer. Stack b is initially empty and must be empty at the end. 
// The stack a must be sorted in descending order.
// The algorithm is based on the following steps:
// 1. Divide the stack a into segments and sort each segment using the stack b as a buffer.
// 2. Merge the segments into a sorted stack a.
void	ft_sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	// int		i;
	// int		segment_size;
	// int		segment_count;
	// If the stack a is empty or contains only one element, return.
	if (stack_a->size == 0 || stack_a->size == 1  || ft_is_sorted(stack_a))
		return ;
	// If the stack a contains only two elements, sort the stack a.
	else if (stack_a->size == 2)
		ft_sort_two(stack_a);
	// If the stack a contains only three elements, sort the stack a.
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
	// If the stack a contains only four elements, sort the stack a.
	else if (stack_a->size == 4)
		ft_sort_four(stack_a, stack_b);
	
	// If the stack a contains more than five elements, sort the stack a.
	// Divide the stack a into segments.
	// segment_size = 5;
	// segment_count = stack_a->size / segment_size;
	// if (stack_a->size % segment_size != 0)
	// 	segment_count++;
	// // Sort each segment using the stack b as a buffer.
	// i = 0;
	// while (i < segment_count)
	// {
	// 	sort_segment(stack_a, stack_b, segment_size);
	// 	i++;
	// }
	// // Merge the segments into a sorted stack a.
	// merge_segments(stack_a, stack_b, segment_count);
}