/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:08:17 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/11 18:57:20 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge(t_stacks *stacks, int front, int middle, int rear)
{
	
}

void	merge_sort(t_stacks *stacks, int front, int rear)
{
	int	middle;

	if (front < rear)
	{
		middle = front + (rear - 1) / 2;
		merge_sort(stacks, front, middle);
		merge_sort(stacks, middle + 1, rear);
	}
	merge(stacks, front, middle, rear);
}
