/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:00:53 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/26 05:45:25 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restack(t_stacks *stacks, int size, int condition, int restack_or_not)
{
	int	i;

	i = -1;
	if (restack_or_not == 1)
	{
		push(stacks, 'b');
		push(stacks, 'b');
		if (ft_oddeven(stacks->mrg_count) == 0)
			stacks->mrg_cond++;
		if ((ft_oddeven(stacks->mrg_cond) == 0 && stacks->b[0] > stacks->b[1])
			|| (ft_oddeven(stacks->mrg_cond) == 1
				&& stacks->b[0] < stacks->b[1]))
			swap(stacks, 'b');
		stacks->mrg_cond++;
		stacks->mrg_count++;
		stacks->mrg_stack++;
	}
	else if (restack_or_not == 2)
	{
		while (++i < size / 2)
		{
			r_rotate(stacks, (condition == 1) * 'a' + (condition == 2) * 'b');
			push(stacks, (condition == 1) * 'b' + (condition == 2) * 'a');
		}
	}
}

void	cont_extra(t_stacks *stacks, int size, int condition)
{
	if (size == 4)
		restack(stacks, size, condition, 1);
	else
		restack(stacks, size, condition, 2);
	if (condition == 1)
	{
		stacks->sorted_a -= power_ten(get_power(size / 2));
		stacks->sorted_b += power_ten(get_power(size / 2 + 1));
		selection_to_a(stacks, size);
	}
	else if (condition == 2)
	{
		stacks->sorted_b -= power_ten(get_power(size / 2));
		stacks->sorted_a += power_ten(get_power(size / 2 + 1));
		selection_to_b(stacks, size);
	}
}

void	extra(t_stacks *stacks, int size, int condition)
{
	if (size == 4)
		stacks->sorted_a++;
	if (size == 8)
		stacks->sel_cond++;
	if (condition == 0)
		cont_extra(stacks, size, 1);
	else if (condition == 1)
		cont_extra(stacks, size, 2);
}
