/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:38:15 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/26 05:45:06 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_or_not(t_stacks *stacks, int size, int stack)
{
	int	pwr;
	int	num;

	pwr = get_power(size + 1);
	num = (int)power_ten(pwr);
	if (stack == 'a' && ft_oddeven(stacks->sorted_a / num) == 1)
		return (0);
	else if (stack == 'b' && ft_oddeven(stacks->sorted_b / num) == 1)
		return (0);
	return (1);
}

void	cont(t_stacks *stacks, int stack, int pwr)
{
	int	num;

	num = (int)power_ten(pwr);
	if (stack == 'a')
	{
		stacks->sorted_a += num;
		stacks->sorted_b -= (num / 10) * 2;
	}
	else if (stack == 'b')
	{
		stacks->sorted_b += num;
		stacks->sorted_a -= (num / 10) * 2;
	}
}

void	plus_sel_stack(t_stacks *stacks, int stack, int size)
{
	int	pwr;

	pwr = get_power(size + 1);
	cont(stacks, stack, pwr);
}
