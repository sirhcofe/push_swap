/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:20:00 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/18 19:10:53 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// location: a - push b to a
//           b - push a to b
void	push(t_stacks *stacks, int location)
{
	int	temp;

	if (location == 'a' && stacks->b_len > 0)
	{
		temp = stacks->b[0];
		move_stack(stacks->b, stacks->b_len, 'u');
		stacks->b_len--;
		stacks->a_len++;
		move_stack(stacks->a, stacks->a_len, 'd');
		stacks->a[0] = temp;
		ft_putstr_fd("pa\n", 1);
	}
	if (location == 'b' && stacks->a_len > 0)
	{
		temp = stacks->a[0];
		move_stack(stacks->a, stacks->a_len, 'u');
		stacks->a_len--;
		stacks->b_len++;
		move_stack(stacks->b, stacks->b_len, 'd');
		stacks->b[0] = temp;
		ft_putstr_fd("pb\n", 1);
	}
}
