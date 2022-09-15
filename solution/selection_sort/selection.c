/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:00:58 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/15 21:36:18 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prelude_two(t_stacks *stacks, int size)
{
	int	i;

	i = -1;
	if (size == 8)
	{
		while (++i < 3)
			rotate(stacks, 'b');
		push(stacks, 'a');
		while (--i != -1)
		{
			r_rotate(stacks, 'b');
			push(stacks, 'a');
		}
		stacks->sorted_stack_in_a++;
		stacks->sorted_stack_in_b--;
	}
}

void	prelude(t_stacks *stacks, int size)
{
	if (size == 2)
	{
		stacks->mrg_cond++;
		stacks->mrg_count++;
		stacks->sorted_stack_in_a++;
	}
	else if (size == 4)
	{
		r_rotate(stacks, 'a');
		push(stacks, 'b');
		r_rotate(stacks, 'a');
		push(stacks, 'b');
		stacks->sorted_stack_in_b++;
		stacks->sorted_stack_in_a--;
		stacks->sel_cond++;
		stacks->mrg_count++;
	}
	prelude_two(stacks, size);
}

void	selection_sort(t_stacks *stacks, int size)
{
	int	i;

	i = -1;
	prelude(stacks, size);
	if (stacks->sorted_stack_in_a >= 2)
	{
		selection_to_b(stacks, size);
		stacks->sorted_stack_in_b++;
		stacks->sorted_stack_in_a -= 2;
	}
	else if (stacks->sorted_stack_in_b >= 2)
	{
		selection_to_a(stacks, size);
		stacks->sorted_stack_in_a++;
		stacks->sorted_stack_in_b -= 2;
	}
}
