/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:19:08 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/15 17:41:50 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	continue_merge(t_stacks *stacks, int condition, int size)
{
	if (condition == 'a')
	{
		if (stacks->a[0] > stacks->a[1])
			swap(stacks, 'a');
	}
	else if (condition == 'd')
	{
		if (stacks->a[0] < stacks->a[1])
			swap(stacks, 'a');
	}
	stacks->mrg_cond++;
	stacks->mrg_count++;
	stacks->sorted_stack_in_a++;
}

/**
 * @brief
 * This is the initial sorting function after the recursion which split the
 * array into groups of 3~4 numbers, the function will then push half of the
 * group to stacks->b where swapping() will be called to sort the numbers in
 * ascending order
 * @param stacks a struct that stores information about the array and array_len
 * on both stacks
 * @param front  the first index of the group
 * @param middle the middle index of the group
 * @param rear   the last index of the group
 */
void	merge_sort(t_stacks *stacks, int front, int rear)
{
	int	i;

	if (ft_oddeven(stacks->mrg_count) == 0 && stacks->mrg_count != 0)
		stacks->mrg_cond++;
	if (ft_oddeven(stacks->mrg_cond) == 0)
		continue_merge(stacks, 'a', rear - front);
	else
		continue_merge(stacks, 'd', rear - front);
	i = -1;
	if (ft_oddeven(stacks->mrg_count) == 1 && stacks->a_len != rear - front + 1)
	{
		while (++i < rear - front + 1)
			rotate(stacks, 'a');
	}
}
