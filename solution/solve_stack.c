/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:08:17 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/11 14:43:44 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * This recursion function will call itself until the stack is 'split'
 * into 3 or 4 numbers
 * @param stacks struct which holds information on both stacks of number(s)
 * @param front the first index of group of numbers after being split
 * @param rear the last index of group of numbers after being split
 */
void	solution(t_stacks *stacks, int front, int rear)
{
	int	middle;

	if (front < rear - 1)
	{
		middle = front + ((rear - front) / 2);
		solution(stacks, front, middle);
		solution(stacks, middle + 1, rear);
		if (rear - front == 2 || rear - front == 3)
			merge_sort(stacks, front, middle, rear);
		else
			selection_sort(stacks, front, rear);
	}
}

void	solve_stack(t_stacks *stacks)
{
	stacks->mrg_cond = (stacks->end_stack == 0 && stacks->a_len != 4) * 0
		+ (stacks->end_stack == 1 || stacks->a_len == 4) * 1;
	stacks->sel_cond = stacks->mrg_cond;
	if (stacks->a_len == 2)
		solve_two(stacks);
	else if (stacks->a_len == 3)
		solve_three(stacks);
	else if (stacks->a_len == 5)
		solve_five(stacks);
	else
		solution(stacks, 0, stacks->a_len - 1);
	if (stacks->end_stack == 1 || stacks->b_len == 4)
		while (stacks->b_len != 0)
			push(stacks, 'a');
}
