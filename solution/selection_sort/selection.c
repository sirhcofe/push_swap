/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:17:36 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/11 14:43:26 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	modify_mrg_condcount(t_stacks *stacks)
{
	if (ft_oddeven(stacks->mrg_cond) == 1 && ft_oddeven(stacks->mrg_count) == 1)
	{
		stacks->mrg_cond--;
		stacks->mrg_count++;
	}
	if (ft_oddeven(stacks->mrg_count) == 0)
		stacks->mrg_cond--;
	else if (ft_oddeven(stacks->mrg_count) == 1)
		stacks->mrg_count++;
}

void	big_selection(t_stacks *stacks, int size)
{
	if (end_stack_location(size + 1) == 1)
		selection_to_b(stacks, size);
	else if (end_stack_location(size + 1) == 0)
		selection_to_a(stacks, size);
}

void	continue_selection(t_stacks *stacks, int size, int condition)
{
	if (condition == 1)
		selection_to_a(stacks, size);
	else
		big_selection(stacks, size);
}

// first if  : for group of n^2 + 1 numbers (n > 0)
// third if  : for group of 6~8 numbers
// fourth if : for group of any other numbers
void	selection_sort(t_stacks *stacks, int front, int rear)
{
	if (stacks->b_rotate == 1)
	{
		rotate(stacks, 'b');
		stacks->b_rotate--;
	}
	if (check_edge_case(stacks, rear - front + 1) != 2)
		extra(stacks, rear - front, check_edge_case(stacks, rear - front + 1));
	else if (rear - front >= 5 && rear - front <= 7)
		continue_selection(stacks, rear - front, 1);
	else
		continue_selection(stacks, rear - front, 2);
	if (rear - front >= 8)
		modify_mrg_condcount(stacks);
}
