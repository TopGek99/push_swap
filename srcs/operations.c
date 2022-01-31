/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:26:22 by arowe             #+#    #+#             */
/*   Updated: 2021/11/08 10:26:24 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(stack *s)
{
	int	temp;

	temp = s->values[s->top];
	s->values[s->top] = s->values[s->top - 1];
	s->values[s->top - 1] = temp;
}

void	pushab(stack *a, stack *b)
{
	push(b, pop(a));
}

void	rotate(stack *s)
{
	int	i;
	int	temp;

	i = s->top;
	temp = s->values[s->top];
	while (i > 0)
	{
		s->values[i] = s->values[i - 1];
		i--;
	}
	s->values[0] = temp;
}

void	revrotate(stack *s)
{
	int	i;
	int	temp;

	i = 0;
	temp = s->values[0];
	while (i < s->top)
	{
		s->values[i] = s->values[i + 1];
		i++;
	}
	s->values[s->top] = temp;
}