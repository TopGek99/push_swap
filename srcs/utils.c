/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:32:01 by alex              #+#    #+#             */
/*   Updated: 2022/05/30 18:07:12 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_negative_one(char *num)
{
	if (num[0] == '-' && num[1] == '1' && ft_strlen(num) == 2)
		return (1);
	return (0);
}

int	min(t_list *list)
{
	int		i;
	int		min;
	int		min_index;
	t_node	*temp;

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

int	is_sorted(t_list *list)
{
	t_node	*temp;

	temp = list->head;
	while (temp->next)
	{
		if (temp->next->value < temp->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_unique(int num, t_list *list)
{
	t_node	*temp;

	temp = list->head;
	while (temp)
	{
		if (temp->value == num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	normalise(t_list *list)
{
	t_list	*sorted;
	t_node	*temp;
	t_node	*temp_sorted;
	int		i;

	sorted = new_list();
	sort_list(list, sorted);
	temp = list->head;
	while (temp)
	{
		temp_sorted = sorted->head;
		i = 0;
		while (temp_sorted)
		{
			if (temp->value == temp_sorted->value)
			{
				temp->value = i;
				break ;
			}
			i++;
			temp_sorted = temp_sorted->next;
		}
		temp = temp->next;
	}
	free_list(sorted);
}
