/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:57:50 by arowe             #+#    #+#             */
/*   Updated: 2021/11/05 11:57:53 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_negative_one(char *num)
{
	if (num[0] == '-' && num[1] == '1' && ft_strlen(num) == 2)
		return (1);
	return (0);
}

int min(const int *tab, int size)
{
	int i;
	int	min;
	int min_index;

	i = 0;
	min = 2147483647;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int is_sorted(node *s)
{
	int i;

	i = s->top - 1;
	while (i >= 0)
	{
		if (s->values[i] < s->values[i + 1])
			return (0);
		i--;
	}
	return (1);
}

void	push_swap_three(node *a)
{
	if ((a->values[a->top] > a->values[a->top - 1] && a->values[a->top] < a->values[a->top - 2]) || (a->values[a->top - 1] > a->values[a->top - 2] && a->values[a->top] > a->values[a->top - 1]) || (a->values[a->top] < a->values[a->top - 2] && a->values[a->top - 1] > a->values[a->top - 2]))
	{
		swap(a);
		ft_printf("sa\n");
	}
	if (a->values[a->top] > a->values[a->top - 2] && a->values[a->top - 1] < a->values[a->top - 2])
	{
		rotate(a);
		ft_printf("ra\n");
	}
	else if (a->values[a->top] < a->values[a->top - 1] && a->values[a->top] > a->values[a->top - 2])
	{
		revrotate(a);
		ft_printf("rra\n");
	}
}
void	min_to_top(node *s)
{
	int min_index;

	min_index = min(s->values, s->top + 1);
	while (min(s->values, s->top + 1) != s->top)
	{
		if (min_index >= (s->top + 1) / 2)
		{
			rotate(s);
			ft_printf("ra\n");
		}
		else
		{
			revrotate(s);
			ft_printf("rra\n");
		}
	}
}

void	push_swap_five(node *a, node *b)
{
	int size = a->top;

	if (is_sorted(a))
		return ;
	while (a->top > 2)
	{
		min_to_top(a);
		pushab(a, b);
		ft_printf("pb\n");
	}
	push_swap_three(a);
	while (a->top < size)
	{
		pushab(b, a);
		ft_printf("pa\n");
	}
}

void push_swap(node *a, node *b, int n)
{
	if (n == 2 && a->values[1] > a->values[0])
	{
		swap(a);
		ft_printf("sa\n");
	}
	else if (n == 3)
		push_swap_three(a);
	else if (n > 3)
		push_swap_five(a, b);
}

int main(int argc, char *argv[])
{
	node *a;
	node *b;
	int 	i;
	int		charnum;

	a = new_node(argc - 1);
	b = new_node(argc - 1);
	i = argc - 1;
	while (i > 0 && argv[i])
	{
		charnum = ft_atoi(argv[i]);
		if (charnum == -1 && !is_negative_one(argv[i]))
		{
			ft_printf("Error\n");
			free(a->values);
			free(a);
			free(b->values);
			free(b);
			return (0);
		}
		push(a, charnum);
		i--;
	}
	push_swap(a, b, argc - 1);
	return (0);
}
                                                                                                                                                                                             