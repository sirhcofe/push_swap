/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:08:17 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/12 18:55:25 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	merge(t_stacks *stacks, int front, int middle, int rear)
{
	int	i[3];
	int	size1;
	int	size2;

	size1 = middle - front;
	size2 = rear - middle;
	
	push(stacks->)
}

void	merge_sort(t_stacks *stacks, int front, int rear)
{
	int	middle;

	front = 
	if (front < rear)
	{
		middle = front + (rear / 2);
		merge_sort(stacks, front, middle);
		merge_sort(stacks, middle + 1, rear);
		merge(stacks, front, middle, rear);
	}
}
