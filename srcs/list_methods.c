/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:24:03 by arowe             #+#    #+#             */
/*   Updated: 2021/11/08 09:24:06 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node	*new_list(int value)
{
	node	*new;

	new = malloc(sizeof(value));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	node_add_front(node **list, node *new)
{
	new->next = *list;
	*list = new;
}

void	node_add_back(node **list, node *new)
{
	node *n;

	n = *list;
	while (n->next)
		n = n->next;
	n->next = new;
}