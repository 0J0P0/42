/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:09:12 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/01/30 16:09:12 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Movement functions.

void	ft_print_move(char *move, char id)
{
	if (id == 'a')
		ft_printf("%sa\n", move);
	else if (id == 'b')
		ft_printf("%sb\n", move);
	else
		ft_printf("%s\n", move);
}

// Swap the top two elements of the stack. sx
void	ft_sx(t_stack *stack)
{
	t_node	*node;

	// If the stack is empty or has only one element, do nothing.
	if (stack->size == 0 || stack->size == 1)
		return ;
	// If the stack has two elements, swap them.
	if (stack->size == 2)
	{
		node = stack->top;
		stack->top = stack->top->next;
		stack->top->next = node;
		stack->top->prev = NULL;
		stack->bottom = node;
		stack->bottom->next = NULL;
		stack->bottom->prev = stack->top;
	}
	// If the stack has more than two elements, swap the top two elements.
	else
	{
		node = stack->top;
		stack->top = stack->top->next;
		stack->top->next->prev = node;
		stack->top->prev = NULL;
		node->next = stack->top->next;
		node->prev = stack->top;
		stack->top->next = node;
	}
	ft_print_move("s", stack->id);
}

// Swap the top two elements of both stacks. ss
void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sx(stack_a);
	ft_sx(stack_b);
	ft_print_move("ss", 0);
}

// Push the top element of the stack y to the top of the stack x. px
void	ft_px(t_stack *stack_x, t_stack *stack_y)
{
	t_node	*node;

	// If the stack y is empty, do nothing.
	if (stack_y->size == 0)
		return ;
	// If the stack x is empty, push the top element of stack y to stack x.
	if (stack_x->size == 0)
	{
		node = stack_y->top;
		stack_y->top = stack_y->top->next;
		stack_y->size--;
		node->next = NULL;
		node->prev = NULL;
		stack_x->top = node;
		stack_x->bottom = node;
		stack_x->size++;
	}
	// If the stack x is not empty, push the top element of stack y to stack x.
	else
	{
		node = stack_y->top;
		stack_y->top = stack_y->top->next;
		stack_y->size--;
		node->prev = NULL;
		node->next = stack_x->top;
		stack_x->top = node;
		stack_x->size++;
	}
	ft_print_move("p", stack_x->id);
}

// Rotate the stack x up by one. The first element becomes the last one. rx
void	ft_rx(t_stack *stack)
{
	t_node	*node;

	// If the stack is empty or has only one element, do nothing.
	if (stack->size < 2)
		return ;
	// If the stack has two elements, swap them.
	if (stack->size == 2)
	{
		node = stack->top;
		stack->top = stack->bottom;
		stack->bottom = node;
		stack->top->next = NULL;
		stack->bottom->next = stack->top;
	}
	// If the stack has more than two elements, rotate the stack up by one.
	else
	{
		node = stack->top;
		stack->top = stack->top->next;
		stack->bottom->next = node;
		stack->bottom = node;
		stack->bottom->next = NULL;
	}
	ft_print_move("r", stack->id);
}

// Rotate simultaneously the stacks x and y up by one. rr
void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rx(stack_a);
	ft_rx(stack_b);
	ft_print_move("rr", 0);
}

// Reverse rotate the stack x down by one. The last element becomes the first one. rrx
void	ft_rrx(t_stack *stack)
{
	t_node	*node;

	// If the stack is empty or has only one element, do nothing.
	if (stack->size < 2)
		return ;
	// If the stack has two elements, swap them.
	if (stack->size == 2)
	{
		node = stack->top;
		stack->top = stack->bottom;
		stack->bottom = node;
		stack->top->next = NULL;
		stack->bottom->next = stack->top;
	}
	// If the stack has more than two elements, reverse rotate the stack down by one.
	else
	{
		node = stack->top;
		while (node->next != stack->bottom)
			node = node->next;
		stack->bottom->next = stack->top;
		stack->top = stack->bottom;
		stack->bottom = node;
		stack->bottom->next = NULL;
	}
	ft_print_move("rr", stack->id);
}

// Reverse rotate simultaneously the stacks x and y down by one. rrr
void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rrx(stack_a);
	ft_rrx(stack_b);
	ft_print_move("rrr", 0);
}