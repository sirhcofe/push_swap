/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:52:16 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/24 20:52:46 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	condition_one(t_stacks *stacks)
{
	if (stacks->a[1] < stacks->a[2])
		rotate(stacks, 'a');
	else
	{
		swap(stacks, 'a');
		r_rotate(stacks, 'a');
	}
}

void	condition_two(t_stacks *stacks)
{
	if (stacks->a[0] < stacks->a[2])
	{
		push(stacks, 'b');
		swap(stacks, 'a');
		push(stacks, 'a');
	}
	else
		r_rotate(stacks, 'a');
}

void	condition_three(t_stacks *stacks)
{
	if (stacks->a[0] < stacks->a[1])
		return ;
	else
		swap(stacks, 'a');
}

void	solve_three(t_stacks *stacks)
{
	int	i;
	int	max_index;
	int	max_value;

	max_value = stacks->a[0];
	max_index = 0;
	i = -1;
	while (++i < stacks->a_len)
	{
		if (stacks->a[i] > max_value)
		{
			max_value = stacks->a[i];
			max_index = i;
		}
	}
	if (max_index == 0)
		condition_one(stacks);
	else if (max_index == 1)
		condition_two(stacks);
	else if (max_index == 2)
		condition_three(stacks);
}
