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

t_list	*new_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->head = NULL;
	list->length = 0;
	return (list);
}

void	t_node_print(t_list *list)
{
	t_node *temp;

	temp = list->head;
	while (temp)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
	}
}

void	t_node_add_front(t_list *list, int new_val)
{
	t_node *new;

	new = malloc(sizeof(new_val));
	new->value = new_val;
	new->next = list->head;
	list->head = new;
	list->length++;
}

void	t_node_add_back(t_list *list, int new_val)
{
	t_node *temp;
	t_node *new;

	if (!list->head)
	{
		t_node_add_front(list, new_val);
		return;
	}
	else if (list->head->next)
		temp = list->head->next;
	else
		temp = list->head;
	while (temp->next)
		temp = temp->next;
	new = malloc(sizeof(new_val));
	new->value = new_val;
	new->next = NULL;
	temp->next = new;
	list->length++;
}