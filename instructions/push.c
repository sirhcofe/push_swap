/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:20:00 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/10 18:19:19 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// location: r - push a to b
//           l - push b to a
void	push(t_stacks *stacks, int location)
{
	int	temp;

	if (location == 'r')
	{
		temp = stacks->a[0];
		move_stack(stacks->a, stacks->a_len, 'u');
		stacks->a_len--;
		move_stack(stacks->b, stacks->b_len, 'd');
		stacks->b_len++;
		stacks->b[0] = temp;
	}
	if (location == 'l')
	{
		temp = stacks->b[0];
		move_stack(stacks->b, stacks->b_len, 'u');
		stacks->b_len--;
		move_stack(stacks->a, stacks->a_len, 'd');
		stacks->a_len++;
	}
}
