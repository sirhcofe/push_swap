/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:19:08 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/29 21:48:18 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
void	merge_sort(t_stacks *stacks, int front, int middle, int rear)
{
	stacks->grp_alen = rear - middle;
	stacks->grp_blen = middle - front + 1;
	if (stacks->merge_count == 0)
	{
		continue_merge(stacks, 1);
		stacks->merge_count = 1;
	}
	else
	{
		continue_merge(stacks, 2);
		stacks->merge_count = 0;
	}
	stacks->recursion_count--;
}
