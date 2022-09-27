/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:31:44 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/25 20:41:45 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_edge_case(t_stacks *stacks, int size)
{
	int	i;

	i = -1;
	while (++i < 29)
		if (size == stacks->edge_case[i])
			return (end_stack_location(size));
	return (2);
}

void	initiate_edge_case(t_stacks *stacks)
{
	int		i;
	int		count;
	long	number;

	i = 2;
	count = 0;
	number = 0;
	while (number <= 2147483647)
	{
		number = (long)power_two(i);
		if (number <= 2147483647)
			count++;
		i++;
	}
	stacks->edge_case = ft_calloc(count, sizeof(int));
	i = -1;
	while (++i < count)
		stacks->edge_case[i] = (power_two(i + 2) + 1);
}
