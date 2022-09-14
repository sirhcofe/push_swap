/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:17:36 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/13 22:15:04 by chenlee          ###   ########.fr       */
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
		if (stacks->b_len != 3)
		{
			rotate(stacks, 'b');
			rotate(stacks, 'b');
			rotate(stacks, 'b');
		}
		push(stacks, 'b');
		push(stacks, 'b');
		if (ft_oddeven(stacks->mrg_cond) == 1 && stacks->b[0] < stacks->b[1])
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

// condition 1: selection a group of 5 numbers
// condition 2: selection a group of 6~8 numbers
// condition 3: selection a group of 9 numbers
// condition 4: selection a group of >9 numbers
void	selection_sort(t_stacks *stacks, int size, int condition)
{
	if (condition == 1 || condition == 2)
	{
		if (condition == 1)
			extra(stacks, 1);
		selection_to_a(stacks, size);
		stacks->sorted_stack_in_a++;
	}
	else if (condition == 3)
	{
		extra(stacks, 2);
		print_numb(stacks);
		stacks->sel_cond++;
		selection_to_b(stacks, size);
		stacks->sorted_stack_in_a = 0;
		stacks->sorted_stack_in_b++;
	}
	else
		big_selection(stacks, size);
}
