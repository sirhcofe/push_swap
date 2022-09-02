/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:25:45 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/02 17:51:44 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cont_b(t_stacks *stacks, int *a, int *b, int condition)
{
	if (condition == 1)
	{
		push(stacks, 'b');
		(*a)++;
	}
	else if (condition == 2)
	{
		r_rotate(stacks, 'a');
		push(stacks, 'b');
		(*b)++;
	}
	else if (condition == 3)
	{
		push(stacks, 'b');
		(*a)++;
		(*b)++;
	}
}

void	cont_b_dsc(t_stacks *stacks, int size)
{
	int	m;
	int	n;

	m = 0;
	n = 0;
	while (m < size - (size / 2) || n < (size / 2) + 1)
	{
		if (stacks->a[0] < stacks->a[stacks->a_len - 1]
			&& m < size - (size / 2))
			cont_b(stacks, &m, &n, 1);
		else if (n < (size / 2) + 1)
			cont_b(stacks, &m, &n, 2);
		else
			cont_b(stacks, &m, &n, 3);
	}
}

void	cont_b_asc(t_stacks *stacks, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - (size / 2) || j < (size / 2) + 1)
	{
		if (stacks->a[0] > stacks->a[stacks->a_len - 1]
			&& i < size - (size / 2))
			cont_b(stacks, &i, &j, 1);
		else if (j < (size / 2) + 1)
			cont_b(stacks, &i, &j, 2);
		else
			cont_b(stacks, &i, &j, 3);
	}
	i = -1;
	if (stacks->b_len != size + 1)
		while (++i <= size)
			rotate(stacks, 'b');
}

void	selection_to_b(t_stacks *stacks, int size)
{
	if (stacks->sorted_stack_in_b == 0)
		cont_b_asc(stacks, size);
	else
		cont_b_dsc(stacks, size);
}
