/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:58:15 by alex              #+#    #+#             */
/*   Updated: 2022/05/30 16:58:16 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	index;
	int	res;
	int	temp;

	index = 0;
	res = 1;
	temp = 0;
	while (str[index] == ' ' || str[index] == '\n'
		|| str[index] == '\t' || str[index] == '\v'
		|| str[index] == '\f' || str[index] == '\r')
		index++;
	if (str[index] == '-')
	{
		res *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		if ((temp > (temp * 10) || temp > (temp * 10) + (str[index] - '0')) && (((long)temp * 10) + (str[index] - '0')) * res != -2147483648)
			return (-1);
		temp *= 10;
		temp += (str[index++] - '0');
	}
	if (str[index] || (temp == 0 && res == -1))
		return (-1);
	return (temp * res);
}
