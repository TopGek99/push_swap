/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <arowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:26:22 by arowe             #+#    #+#             */
/*   Updated: 2022/05/26 14:13:28 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *head, char stack)
{
	t_node	*temp;

	temp = head->next;
	head->next = temp->next;
	temp->next = head;
	head = temp;
	ft_printf("s%c\n", stack);
}

// stack char specifies which stack the function pushes *to* i.e. if stack == 'a' it pushes from a to b
void	push(t_node *head1, t_node *head2, char stack)
{
	t_node *temp;

	temp = head2;
	head2 = head1;
	head2->next = temp->next;
	temp->next = head1->next;
	head1 = temp;
}

