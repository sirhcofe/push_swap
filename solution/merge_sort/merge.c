/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:19:08 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/27 20:50:47 by chenlee          ###   ########.fr       */
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
	int	i;

	stacks->grp_alen = rear - middle;
	stacks->grp_blen = middle - front + 1;
	if (ft_oddeven(stacks->mrg_count) == 0 && stacks->mrg_count != 0)
		stacks->mrg_cond++;
	if (ft_oddeven(stacks->mrg_cond) == 0)
		continue_merge(stacks, 1);
	else
		continue_merge(stacks, 2);
	i = -1;
	if (stacks->sorted_b % 10 == 0 && stacks->b_len != rear - front + 1)
		while (++i < (rear - front + 1))
			rotate(stacks, 'b');
	stacks->sorted_b += 1;
	stacks->mrg_cond++;
	stacks->mrg_count++;
}
