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

int main(int argc, char *argv[])
{
	stack *a;
	stack *b;
	int 	i;
	int		charnum;

	a = new_stack(argc - 1);
	b = new_stack(argc - 1);
	i = 1;
	while (i < argc && argv[i])
	{
		charnum = ft_atoi(argv[i]);
		if (charnum == -1 && !is_negative_one(argv[i]))
		{
			write(1, "Error\n", 6);
			free(a->values);
			free(a);
			free(b->values);
			free(b);
			return (0);
		}
		push(a, charnum);
		i++;
	}
	return (0);
}
