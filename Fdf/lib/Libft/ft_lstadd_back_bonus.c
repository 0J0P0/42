/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:21:07 by jzaldiva          #+#    #+#             */
/*   Updated: 2022/09/30 16:21:07 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_lst;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		new_lst = ft_lstlast(*lst);
		new_lst->next = new;
	}
}
