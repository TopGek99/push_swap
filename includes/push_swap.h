/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arowe <arowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:52:42 by arowe             #+#    #+#             */
/*   Updated: 2022/05/26 14:09:16 by arowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct linked_lists
{
	int		value;
	t_node	*next;
} t_node;

t_node	*new_list(int value);
int		pop(t_node *s);
void	print_t_node(t_node *s);
void	swap(t_node *s, char stack);
void	push(t_node *head1, t_node *head2, char stack);
void	rotate(t_node *s);
void	revrotate(t_node *s);

#endif