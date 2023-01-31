/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:46:09 by jzaldiva          #+#    #+#             */
/*   Updated: 2023/01/27 16:46:09 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/******************************** INCLUDES ************************************/
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../lib/Libft/libft.h"
# include "../lib/Printf/inc/ft_printf.h"
/******************************************************************************/

/********************************* DEFINES ************************************/
// Stack structure: A stack is a list of nodes, with a top node and a bottom node.
// Also with an integer of size and an identifier.
typedef struct s_stack
{
	char			id;
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
} t_stack;

// Node structure: A node is a structure that contains a value and a pointer to the next node and the previous node. Also an index inside the stack.
typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;
/******************************************************************************/
/********************************* PROTOTYPES *********************************/
void	ft_print_move(char *move, char id);

void	ft_sx(t_stack *stack);

void	ft_ss(t_stack *stack_a, t_stack *stack_b);

void	ft_px(t_stack *stack_x, t_stack *stack_y);

void	ft_rx(t_stack *stack);

void	ft_rr(t_stack *stack_a, t_stack *stack_b);

void	ft_rrx(t_stack *stack);

void	ft_rrr(t_stack *stack_a, t_stack *stack_b);
/******************************************************************************/
void free_stack(t_stack *stack);

void print_stack(t_stack *stack);

void test(t_stack *stack_a, t_stack *stack_b);

t_stack *init_stack(int argc, char *argv[], char id);
/******************************************************************************/
void		ft_error(void);

int			ft_isnum(char *argv);

long long	ft_atoll(const char *nptr);

int			ft_isdup(int argc, char *argv[], int i);

int			ft_valid_parameters(int argc, char *argv[]);
/********************************* END OF FILE ********************************/

# endif