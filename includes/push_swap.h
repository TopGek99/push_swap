/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:52:42 by arowe             #+#    #+#             */
/*   Updated: 2021/11/08 08:52:44 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct Stacks
{
	int	*values;
	int	top;
	int size;
} stack;

stack	*new_stack(int size);
void	push(stack *s, int n);
int		pop(stack *s);
void	swap(stack *s);
void	pushab(stack *a, stack *b);
void	rotate(stack *s);
void	revrotate(stack *s);

#endif