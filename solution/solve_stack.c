/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:08:17 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/21 21:22:01 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

	// printf("Initial front:-%d-; initial rear:-%d-\n", front, rear);
	if (front < rear - 1)
	{
		middle = front + ((rear - front) / 2);
		solution(stacks, front, middle);
		solution(stacks, middle + 1, rear);
		// if (rear - front == 2 || rear - front == 3)
		// 	merge_sort(stacks, front, middle, rear);
		// else
		// 	selection_sort(stacks);
	}
}

void	solve_stack(t_stacks *stacks)
{
	if (stacks->a_len == 3)
	{
		printf("THIS DID RUN\n");
		solve_three(stacks);
	}
	else
		solution(stacks, 0, stacks->a_len - 1);
}
