/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:00:02 by alex              #+#    #+#             */
/*   Updated: 2022/05/30 18:05:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *a, t_list *b, int n)
{
	if (is_sorted(a))
		return ;
	if (n == 2 && a->head->value > a->head->next->value)
		swap(a, 'a');
	else if (n == 3)
		push_swap_three(a);
	else if (n > 3 && n <= 5)
		push_swap_five(a, b);
	else if (n > 5)
		push_swap_big(a, b);
}

void	free_list(t_list *list)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = list->head;
	while (temp1)
	{
		temp2 = temp1;
		temp1 = temp2->next;
		free(temp2);
	}
	free(list);
}

int	error(t_list *a, t_list *b)
{
	write(2, "Error\n", 6);
	free_list(a);
	free_list(b);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		charnum;

	if (argc == 1)
		return (0);
	a = new_list();
	b = new_list();
	i = 1;
	while (argv[i])
	{
		charnum = ft_atoi(argv[i]);
		if ((charnum == -1 && !is_negative_one(argv[i]))
			|| !is_unique(charnum, a))
			return (error(a, b));
		t_node_add_back(a, charnum);
		i++;
	}
	normalise(a);
	push_swap(a, b, argc - 1);
	free_list(a);
	free_list(b);
	return (0);
}
