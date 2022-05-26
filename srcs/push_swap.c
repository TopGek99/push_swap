#include "push_swap.h"

int	is_negative_one(char *num)
{
	if (num[0] == '-' && num[1] == '1' && ft_strlen(num) == 2)
		return (1);
	return (0);
}

int min(const int *tab, int size)
{
	int i;
	int	min;
	int min_index;

	i = 0;
	min = 2147483647;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void push_swap(t_node *a, t_node *b, int n)
{
	if (n == 2 && a->value > a->next->value)
	{
		swap(a);
		ft_printf("sa\n");
	}
	else if (n == 3)
		push_swap_three(a);
	else if (n > 3)
		push_swap_five(a, b);
}

int main(int argc, char *argv[])
{
	t_node *a;
	t_node *b;
	int 	i;
	int		charnum;

	a = new_list(argc - 1);
	b = new_list(argc - 1);
	i = argc - 1;
	while (i > 0 && argv[i])
	{
		charnum = ft_atoi(argv[i]);
		if (charnum == -1 && !is_negative_one(argv[i]))
		{
			ft_printf("Error\n");
			free(a);
			free(b);
			return (0);
		}
		t_node_add_front(a, charnum);
		i--;
	}
	push_swap(a, b, argc - 1);
	return (0);
}
                                                                                                                                                                                             