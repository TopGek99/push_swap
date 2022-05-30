/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:00:02 by alex              #+#    #+#             */
/*   Updated: 2022/05/30 17:25:29 by alex             ###   ########.fr       */
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

int	error(t_list *a, t_list *b)
{
	write(2, "Error\n", 6);
	free(a);
	free(b);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		charnum;

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
	free(a);
	free(b);
	return (0);
}
