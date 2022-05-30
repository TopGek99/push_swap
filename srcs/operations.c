/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:26:22 by arowe             #+#    #+#             */
/*   Updated: 2022/05/26 18:34:27 by alex             ###   ########.fr       */
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

// stack char specifies which stack the function pushes *to* i.e. if stack == 'a' it pushes from a to b
// pushes head1 to top of head2
void push(t_list *list1, t_list *list2, char stack)
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

void rotate(t_list *list, char stack)
{
	t_node *temp_head;
	t_node *temp_count;

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

void rev_rotate(t_list *list, char stack)
{
	t_node *temp_head;
	t_node *temp_count;

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