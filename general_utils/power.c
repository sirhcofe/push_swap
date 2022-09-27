/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:48:42 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/27 17:37:30 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	power_ten(int count)
{
	long	num;
	int		i;

	num = 1;
	i = 0;
	if (count == 0)
		return (1);
	while (i < count - 1)
	{
		num = num * 10;
		i++;
	}
	return (num);
}

long	power_two(int count)
{
	long	num;
	int		i;

	num = 2;
	i = 0;
	if (count == 0)
		return (1);
	while (i < count - 1)
	{
		num = num * 2;
		i++;
	}
	return (num);
}

int	get_power(int size)
{
	int	i;

	i = 0;
	while (power_two(i + 2) <= 2147483647)
	{
		if (power_two(i) + 1 <= size && size <= power_two(i + 1))
			return (i);
		else
			i++;
	}
	return (-1);
}
