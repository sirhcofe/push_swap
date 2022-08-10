/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:10:45 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/10 17:27:38 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// direction: u - moving up
//            d - moving down
void	move_stack(int *array, int size, int direction)
{
	int	i;

	if (direction == 'u')
	{
		i = 0;
		while (i < size - 1)
		{
			array[i] = array[i + 1];
			i++;
		}
	}
	else if (direction == 'd')
	{
		i = size - 1;
		while (i > 0)
		{
			array[i] = array[i - 1];
			i--;
		}
	}
}

// // set: 1 - stack_A
// //      2 - stack_B
// void	move_stack_up(t_stacks *stacks, int set)
// {
// 	int	i;

// 	i = 0;
// 	if (set == 1)
// 	{
// 		while (i < stacks->a_len - 1)
// 		{
// 			stacks->a[i] = stacks->a[i + 1];
// 			i++;
// 		}
// 	}
// 	else if (set == 2)
// 	{
// 		while (i < stacks->b_len - 1)
// 		{
// 			stacks->b[i] = stacks->b[i + 1];
// 			i++;
// 		}
// 	}
// }

// void	move_stack_down(t_stacks *stacks, int set);
// {
// 	int	i;

// 	if (set == 1)
// 	{
// 		i = stacks->a_len;
// 		while (i > 0)
// 		{
// 			stacks->a[i] = stacks->a[i - 1];
// 			i--;
// 		}
// 	}
// 	else if (set == 2)
// 	{
// 		i = stacks->b_len;
// 		while (i > 0)
// 		{
// 			stacks->b[i] = stacks->b[i - 1];
// 			i--;
// 		}
// 	}
// }