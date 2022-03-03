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

typedef struct Linked_lists
{
	int		value;
	node	*next;
} node;

node	*new_list(int value);
void	push(node *s, int n);
int		pop(node *s);
void	print_node(node *s);
void	swap(node *s);
void	pushab(node *a, node *b);
void	rotate(node *s);
void	revrotate(node *s);

#endif