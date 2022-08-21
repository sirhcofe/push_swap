/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:19:08 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/21 21:18:38 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	continue_select(t_stacks *stacks, int j);

void	small_selection(t_stacks *stacks, int front, int middle, int rear)
{
	int	i;
	int	j;

	while (i <= middle - front - 1)
	{
		j = 0;
		while (stacks->a[j] < stacks->b[0] && j <= rear - middle)
			j++;
		continue_fn(stacks, j);
	}
}

/**
 * @brief
 * This is the initial sorting function that will be called after recursion.
 * will call 'swap' instruction to modify the arrangement
 * of number(s)
 * 
 * @param stacks function where swapping takes place into ascending order
 */
void	swapping(t_stacks *stacks)
{
	if (stacks->a[0] < stacks->a[1] && stacks->b[0] < stacks->b[1]
				&& stacks->a_len > 1 && stacks->b_len > 1)
		swap(stacks, 's');
	else if (stacks->a[0] < stacks->a[1])
		swap(stacks, 'a');
	else if (stacks->b[0] < stacks->a[1])
		swap(stacks, 'b');
}

/**
 * @brief
 * This is the initial sorting function that will be called after recursion.
 * will call 'swap' instruction to modify the arrangement
 * of number(s)
 */
void	merge_sort(t_stacks *stacks, int front, int middle, int rear)
{
	int	i;

	i = 0;
	// if (rear - front == 2 || rear - front == 3)
	// 	merge_four(stacks, front - stacks->index,
	// 		middle - stacks->index, rear - stacks->index);
	// else
		selection_sort(stacks, front - stacks->index,
			middle - stacks->index, rear - stacks->index);
}