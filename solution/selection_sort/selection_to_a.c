/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:50:42 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/26 04:10:58 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cont_a(t_stacks *stacks, int *a, int *b, int condition)
{
	if (condition == 1)
	{
		push(stacks, 'a');
		(*a)++;
	}
	else if (condition == 2)
	{
		r_rotate(stacks, 'b');
		push(stacks, 'a');
		(*b)++;
	}
	else if (condition == 3)
	{
		push(stacks, 'a');
		(*a)++;
		(*b)++;
	}
}

void	cont_a_dsc(t_stacks *stacks, int size)
{
	int	m;
	int	n;

	m = 0;
	n = 0;
	while (m < size - (size / 2) || n < (size / 2) + 1)
	{
		if (stacks->b[0] < stacks->b[stacks->b_len - 1]
			&& m < size - (size / 2))
			cont_a(stacks, &m, &n, 1);
		else if (n < (size / 2) + 1)
			cont_a(stacks, &m, &n, 2);
		else
			cont_a(stacks, &m, &n, 3);
	}
}

void	cont_a_asc(t_stacks *stacks, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - (size / 2) || j < (size / 2) + 1)
	{
		if (stacks->b[0] > stacks->b[stacks->b_len - 1]
			&& i < size - (size / 2))
			cont_a(stacks, &i, &j, 1);
		else if (j < (size / 2) + 1)
			cont_a(stacks, &i, &j, 2);
		else
			cont_a(stacks, &i, &j, 3);
	}
}

void	selection_to_a(t_stacks *stacks, int size)
{
	int	i;

	if (ft_oddeven(stacks->sel_cond) == 0)
		cont_a_asc(stacks, size);
	else
		cont_a_dsc(stacks, size);
	stacks->sel_cond++;
	plus_sel_stack(stacks, 'a', size);
	stacks->mrg_stack = 0;
	i = -1;
	if (rotate_or_not(stacks, size, 'a') == 0 && stacks->a_len != size + 1)
	{
		while (++i <= size)
			rotate(stacks, 'a');
	}
}
