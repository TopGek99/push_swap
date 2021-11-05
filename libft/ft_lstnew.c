/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:58:44 by arowe             #+#    #+#             */
/*   Updated: 2021/10/08 12:58:44 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *first)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(first));
	if (!new_lst)
		return (NULL);
	new_lst->content = first;
	new_lst->next = NULL;
	return (new_lst);
}
