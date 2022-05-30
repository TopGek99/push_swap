/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:31:24 by alex              #+#    #+#             */
/*   Updated: 2022/05/26 18:43:23 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_negative_one(char *num)
{
	if (num[0] == '-' && num[1] == '1' && ft_strlen(num) == 2)
		return (1);
	return (0);
}

int min(t_list *list)
{
	int i;
	int	min;
	int min_index;
	t_node *temp;

	i = 0;
	min = 2147483647;
	temp = list->head;
	while (temp)
	{
		if (temp->value < min)
		{
			min = temp->value;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (min_index);
}

int is_sorted(t_list *list)
{
	t_node *temp;

	temp = list->head;
	while (temp->next)
	{
		if(temp->next->value < temp->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	push_swap_three(t_list *a)
{
	if (is_sorted(a))
		return ;
	else if (a->head->value > a->head->next->value && (a->head->value < a->head->next->next->value || a->head->next->value > a->head->next->next->value))
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
	{
		rotate(a, 'a');
	}
}

void push_swap_five(t_list *a, t_list *b)
{
	while (a->length > 3)
	{
		if (min(a) < a->length / 2)
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
	}
	push_swap_three(a);
	push(b, a, 'a');
	push(b, a, 'a');
}

void push_swap(t_list *a, t_list *b, int n)
{
	if (n == 2 && a->head->value > a->head->next->value)
		swap(a, 'a');
	else if (n == 3)
		push_swap_three(a);
	else if (n > 3 && n <= 5)
		push_swap_five(a, b);
}

int main(int argc, char *argv[])
{
	t_list *a;
	t_list *b;
	int 	i;
	int		charnum;

	a = new_list();
	b = new_list();
	i = 1;
	while (argv[i] && argc)
	{
		charnum = ft_atoi(argv[i]);
		if (charnum == -1 && !is_negative_one(argv[i]))
		{
			ft_printf("Error\n");
			free(a);
			free(b);
			return (0);
		}
		t_node_add_back(a, charnum);
		i++;
	}
	push_swap(a, b, argc - 1);
	return (0);
}
                                                                                                                                                                                             