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

t_node	*new_list(int value)
{
	t_node	*new;

	new = malloc(sizeof(value));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	t_node_add_front(t_node *head, int new_val)
{
	t_node *new;

	new = malloc(sizeof(new_val));
	new->value = new_val;
	new->next = head;
	head = new;
}

void	t_node_add_back(t_node *head, int new_val)
{
	t_node *temp;
	t_node *new;

	if (head->next)
		temp = head->next;
	else
		temp = head;
	while (temp->next)
		temp = temp->next;
	new = malloc(sizeof(new_val));
	new->value = new_val;
	new->next = NULL;
	temp->next = new;
}