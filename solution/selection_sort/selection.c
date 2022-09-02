/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:17:36 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/03 01:27:37 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_selection(t_stacks *stacks, int size)
{
	if (stacks->sorted_stack_in_a == 2)
	{
		selection_to_b(stacks, size);
		stacks->sorted_stack_in_b++;
		stacks->sorted_stack_in_a = 0;
	}
	else if (stacks->sorted_stack_in_b == 2)
	{
		selection_to_a(stacks, size);
		stacks->sorted_stack_in_a++;
		stacks->sorted_stack_in_b = 0;
	}
}

void	extra(t_stacks *stacks, int condition)
{
	if (condition == 1)
	{
		rotate(stacks, 'b');
		rotate(stacks, 'b');
		rotate(stacks, 'b');
		push(stacks, 'b');
		push(stacks, 'b');
		if (stacks->sorted_stack_in_a == 0 && stacks->b[0] < stacks->b[1])
			swap(stacks, 'b');
		else if (stacks->b[0] > stacks->b[1])
			swap(stacks, 'b');
	}
	else if (condition == 2)
	{
		while (stacks->b_len != 0)
		{
			r_rotate(stacks, 'b');
			push(stacks, 'a');
		}
	}
}

void	selection_sort(t_stacks *stacks, int size, int condition)
{
	int	i;

	printf("SIZE = %d\n", size);
	i = -1;
	if (condition == 1 || condition == 2)
	{
		if (condition == 1)
			extra(stacks, 1);
		stacks->recursion_count--;
		selection_to_a(stacks, size);
		stacks->sorted_stack_in_a++;
	}
	else if (condition == 3)
	{
		stacks->recursion_count--;
		extra(stacks, 2);
		selection_to_b(stacks, size);
		stacks->sorted_stack_in_a = 0;
		stacks->sorted_stack_in_b++;
	}
	else
	{
		stacks->recursion_count--;
		big_selection(stacks, size);
	}
}
