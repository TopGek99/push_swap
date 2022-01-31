/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:24:03 by arowe             #+#    #+#             */
/*   Updated: 2021/11/08 09:24:06 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*new_stack(int size)
{
	stack	*new;

	new = malloc(sizeof(stack));
	new->values = malloc(sizeof(int) * size);
	new->top = -1;
	new->size = size;
	return new;
}

void	push(stack *s, int n)
{
	s->values[++s->top] = n;
}

int	pop(stack *s)
{
	return (s->values[s->top--]);
}

void	print_stack(stack *s)
{
	int i;

	i = s->top;
	while (i >= 0)
		ft_printf("%d\n",s->values[i--]);
}