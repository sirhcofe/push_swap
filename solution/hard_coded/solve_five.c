/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:33:46 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/28 18:08:01 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	r_rotate_solve(t_stacks *stacks, int position)
{
	if (position == 3)
	{
		push(stacks, 'a');
		rotate(stacks, 'a');
		push(stacks, 'a');
		rotate(stacks, 'a');
	}
	else if (position == 2)
	{
		r_rotate(stacks, 'a');
		push(stacks, 'a');
		rotate(stacks, 'a');
		if (stacks->b[0] < stacks->a[0])
		{
			push(stacks, 'a');
			rotate(stacks, 'a');
		}
		else
		{
			rotate(stacks, 'a');
			push(stacks, 'a');
		}
		rotate(stacks, 'a');
	}
}

void	rotate_solve(t_stacks *stacks, int position)
{
	int	i;

	i = -1;
	while (++i < position)
		rotate(stacks, 'a');
	push(stacks, 'a');
	rotate(stacks, 'a');
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
	if (stacks->b_len != 0)
	{
		push(stacks, 'a');
		rotate(stacks, 'a');
	}
}

void	cont_solve_five(t_stacks *stacks, int position, int condition)
{
	if (condition == 1)
		rotate_solve(stacks, position);
	else if (condition == 2)
		r_rotate_solve(stacks, position);
}

int	insertion_position(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (stacks->b[0] < stacks->a[i])
			return (i);
	}
	return (i);
}

void	solve_five(t_stacks *stacks)
{
	int	position;

	push(stacks, 'b');
	push(stacks, 'b');
	solve_three(stacks);
	if (stacks->b[0] > stacks->b[1])
		swap(stacks, 'b');
	position = insertion_position(stacks);
	if (position >= 2)
		cont_solve_five(stacks, position, 2);
	else
		cont_solve_five(stacks, position, 1);
}
