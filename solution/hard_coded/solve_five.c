/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:33:46 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/28 22:11:31 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_two_smallest(t_stacks *stacks, int *array, int times_run)
{
	int	n;
	int	temp;

	n = 0;
	if (times_run == 2 && array[0] == stacks->a[0])
		temp = stacks->a[1];
	else
		temp = stacks->a[0];
	while (++n < 5)
	{
		if (stacks->a[n] < temp)
			if (stacks->a[n] != array[0])
				temp = stacks->a[n];
	}
	if (times_run == 1)
	{
		array[0] = temp;
		find_two_smallest(stacks, array, 2);
	}
	else if (times_run == 2)
		array[1] = temp;
}

void	solve_five(t_stacks *stacks)
{
	int	*array;
	int	i;
	int	push_count;

	i = 0;
	push_count = 0;
	array = malloc(sizeof(int) * 2);
	find_two_smallest(stacks, array, 1);
	while (push_count != 2)
	{
		if (stacks->a[0] == array[0] || stacks->a[0] == array[1])
		{
			push(stacks, 'b');
			push_count++;
		}
		else
			rotate(stacks, 'a');
	}
	solve_three(stacks);
	if (stacks->b[0] < stacks->b[1])
		swap(stacks, 'b');
	push(stacks, 'a');
	push(stacks, 'a');
	free(array);
}
