/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:17:36 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/02 19:39:56 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	modify_mrg_condcount(t_stacks *stacks, int size)
{
	int	group;

	group = ((size <= 17) * 1) + ((size > 17 && size < 33) * 2);
	// if (ft_oddeven(stacks->mrg_cond) == 1 && ft_oddeven(stacks->mrg_count) == 1)
	// {
	// 	stacks->mrg_cond--;
	// 	stacks->mrg_count++;
	// }
	if (ft_oddeven(stacks->mrg_count) == 0)
		stacks->mrg_cond -= group;
	else if (ft_oddeven(stacks->mrg_count) == 1)
		stacks->mrg_count += group;
}

void	big_selection(t_stacks *stacks, int size)
{
	if (end_stack_location(size + 1) == 1)
		selection_to_b(stacks, size);
	else if (end_stack_location(size + 1) == 0)
		selection_to_a(stacks, size);
}
// if (stacks->sorted_a > power_ten(get_power(size + 1)) / 10
// 	&& ft_oddeven(stacks->sorted_a
// 		/ (power_ten(get_power(size + 1)) / 10)) == 0)
// 	selection_to_b(stacks, size);
// else if (stacks->sorted_b > power_ten(get_power(size + 1)) / 10
// 	&& ft_oddeven(stacks->sorted_b
// 		/ (power_ten(get_power(size + 1)) / 10)) == 0)
// 	selection_to_a(stacks, size);

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
	if (check_edge_case(stacks, rear - front + 1) != 2)
		extra(stacks, rear - front, check_edge_case(stacks, rear - front + 1));
	else if (rear - front >= 5 && rear - front <= 7)
		continue_selection(stacks, rear - front, 1);
	else
		continue_selection(stacks, rear - front, 2);
	if (rear - front >= 8)
		modify_mrg_condcount(stacks, rear - front + 1);
}

	// if (rear - front >= 8)
	// 	modify_mrg_condcount(stacks, 1);
