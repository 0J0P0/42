/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaldiva <jzaldiva@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:15:54 by jzaldiva          #+#    #+#             */
/*   Updated: 2022/09/21 16:16:01 by jzaldiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;
	void	*tmp;

	if (!lst)
		return (0);
	new_list = 0;
	while (lst)
	{
		tmp = f(lst->content);
		new_element = ft_lstnew(tmp);
		if (!new_element)
		{
			ft_lstclear(&new_list, del);
			free(tmp);
			return (0);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
