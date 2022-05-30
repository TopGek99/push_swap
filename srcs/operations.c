/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:26:22 by arowe             #+#    #+#             */
/*   Updated: 2022/05/30 17:28:49 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *list, char stack)
{
	t_node	*temp;

	temp = list->head->next;
	list->head->next = temp->next;
	temp->next = list->head;
	list->head = temp;
	ft_printf("s%c\n", stack);
}

void	push(t_list *list1, t_list *list2, char stack)
{
	t_node	*temp;

	temp = list1->head;
	list1->head = temp->next;
	temp->next = list2->head;
	list2->head = temp;
	list2->length++;
	list1->length--;
	ft_printf("p%c\n", stack);
}

void	rotate(t_list *list, char stack)
{
	t_node	*temp_head;
	t_node	*temp_count;

	temp_head = list->head;
	list->head = temp_head->next;
	if (list->head->next)
		temp_count = list->head->next;
	else
		temp_count = list->head;
	while (temp_count->next)
		temp_count = temp_count->next;
	temp_count->next = temp_head;
	temp_head->next = NULL;
	ft_printf("r%c\n", stack);
}

void	rev_rotate(t_list *list, char stack)
{
	t_node	*temp_head;
	t_node	*temp_count;

	if (list->head->next)
		temp_count = list->head->next;
	else
		temp_count = list->head;
	while (temp_count->next->next)
		temp_count = temp_count->next;
	temp_head = temp_count->next;
	temp_count->next = NULL;
	temp_head->next = list->head;
	list->head = temp_head;
	ft_printf("rr%c\n", stack);
}
