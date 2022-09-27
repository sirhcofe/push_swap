/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:33:46 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/27 18:12:32 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cont_solve_five(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (stacks->b[0] < stacks->a[0] && stacks->b_len != 0)
		{
			push(stacks, 'a');
			rotate(stacks, 'a');
		}
		else
		{
			rotate(stacks, 'a');
			i++;
		}
	}
	while (stacks->b_len != 0)
	{
		push(stacks, 'a');
		rotate(stacks, 'a');
	}
}

void	solve_five(t_stacks *stacks)
{
	push(stacks, 'b');
	push(stacks, 'b');
	solve_three(stacks);
	if (stacks->b[0] > stacks->b[1])
		swap(stacks, 'b');
	cont_solve_five(stacks);
}
