/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:58:44 by arowe             #+#    #+#             */
/*   Updated: 2021/10/08 12:58:44 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*contents(t_list *lst, t_list *new_iter,
	t_list *new, void (*del)(void *))
{
	if (!new_iter)
	{
		while (new)
		{
			new_iter = new->next;
			del(new->content);
			free(new);
			new = new_iter;
		}
		lst = NULL;
	}
	return (lst);
}

t_list	*ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_iter;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		node = lst;
		f(node->content);
		new_iter = ft_lstnew(node->content);
		if (!contents(lst, new_iter, new, del))
			return (NULL);
		ft_lstadd_back(&new, new_iter);
		lst = lst->next;
	}
	return (new);
}
