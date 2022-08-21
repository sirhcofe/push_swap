/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:53:11 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/20 21:53:40 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	selection_sort(t_stacks *stacks, int front, int middle, int rear)
{
	int	i;

	i = -1;
	while (++i <= rear - middle)
		push(stacks, 'b');
	
}

// void	continue_fn(t_stacks *stacks, int *i, int *j, int condition)
// {
// 	if (condition == 1 || condition == 2)
// 	{
// 		push(stacks, 'a');
// 		if (condition == 2)
// 			rotate(stacks, 'a');
// 		(*i)++;
// 	}
// 	else if (condition == 3)
// 	{
// 		r_rotate(stacks, 'a');
// 		push(stacks, 'a');
// 		rotate(stacks, 'a');
// 		(*i)++;
// 	}
// 	else if (condition == 4)
// 	{
// 		rotate(stacks, 'a');
// 		(*j)++;
// 	}
// }

// void	selection_sort(t_stacks *stacks, int front, int middle, int rear)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i <= middle - front - 1 && j <= rear - middle)
// 	{
// 		if (stacks->a[0] > stacks->b[0])
// 			continue_fn(stacks, &i, &j, 1);
// 		else if ((stacks->a[0] < stacks->b[0]
// 				&& stacks->a[rear - middle + i] > stacks->b[0]))
// 			continue_fn(stacks, &i, &j, 2);
// 		else if (stacks->a[0] < stacks->b[0]
// 				&& stacks->a[rear - middle + i] > stacks->b[0])
// 			continue_fn(stacks, &i, &j, 3);
// 		else
// 			continue_fn(stacks, &i, &j, 4);
// 	}
// 	while (i <= middle - front - 1)
// 	{
// 		push(stacks, 'a');
// 		rotate(stacks, 'a');
// 		i++;
// 	}
// 	while (j <= rear - middle)
// 	{
// 		rotate(stacks, 'a');
// 		j++;
// 	}
// }
