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

#include "../libft/libft.h"
#include <unistd.h>

int main(void)
{
	char *str = "Hello World";
	int len;

	len = ft_strlen(str);
	write(1, str, len);

	return (0);
}
