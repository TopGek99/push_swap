/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:28:31 by alex              #+#    #+#             */
/*   Updated: 2022/05/30 17:31:39 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_three(t_list *a)
{
	if (is_sorted(a))
		return ;
	else if (a->head->value > a->head->next->value
		&& (a->head->value < a->head->next->next->value
			|| a->head->next->value > a->head->next->next->value))
	{
		swap(a, 'a');
		push_swap_three(a);
	}
	else if (a->head->value < a->head->next->value)
	{
		rev_rotate(a, 'a');
		push_swap_three(a);
	}
	else
		rotate(a, 'a');
}

void	push_swap_five(t_list *a, t_list *b)
{
	int	push_amount;

	push_amount = 0;
	while (a->length > 3)
	{
		if (min(a) < (double)a->length / 2)
		{
			while (min(a) != 0)
				rotate(a, 'a');
			push(a, b, 'b');
		}
		else
		{
			while (min(a) != 0)
				rev_rotate(a, 'a');
			push(a, b, 'b');
		}
		push_amount++;
	}
	push_swap_three(a);
	while (push_amount > 0)
	{
		push(b, a, 'a');
		push_amount--;
	}
}

int	max(t_list *list)
{
	int		max;
	t_node	*temp;

	max = -2147483648;
	temp = list->head;
	while (temp)
	{
		if (temp->value > max)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int	get_bit_amount(int max)
{
	int	bit_amount;

	while (max > 0)
	{
		max /= 2;
		bit_amount++;
	}
	return (bit_amount);
}

void	push_swap_big(t_list *a, t_list *b)
{
	int	bit_amount;
	int	i;
	int	j;
	int	a_length;

	bit_amount = get_bit_amount(max(a));
	i = 0;
	a_length = a->length;
	while (i < bit_amount)
	{
		j = 0;
		while (j < a_length)
		{
			if ((((a->head->value) >> i) & 1) == 0)
				push(a, b, 'b');
			else
				rotate(a, 'a');
			j++;
		}
		while (b->length > 0)
			push(b, a, 'a');
		i++;
	}
}
