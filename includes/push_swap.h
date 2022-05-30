/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:52:42 by arowe             #+#    #+#             */
/*   Updated: 2022/05/30 18:06:52 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct linked_list_node
{
	int						value;
	struct linked_list_node	*next;
}	t_node;

typedef struct linked_list
{
	t_node	*head;
	int		length;
}	t_list;

t_list	*new_list(void);
void	t_node_print(t_list *list);
void	t_node_add_front(t_list *list, int new_val);
void	t_node_add_back(t_list *list, int new_val);
void	sort_list(t_list *list, t_list *sorted);
void	swap(t_list *list, char stack);
void	push(t_list *list1, t_list *list2, char stack);
void	rotate(t_list *list, char stack);
void	rev_rotate(t_list *list, char stack);
int		is_sorted(t_list *list);
int		min(t_list *list);
int		is_unique(int num, t_list *list);
int		is_negative_one(char *num);
void	normalise(t_list *list);
void	push_swap_three(t_list *a);
void	push_swap_five(t_list *a, t_list *b);
void	push_swap_big(t_list *a, t_list *b);
void	free_list(t_list *list);

#endif