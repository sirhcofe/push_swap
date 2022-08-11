/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:20:00 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/11 14:03:03 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// location: r - push a to b
//           l - push b to a
void	push(t_stacks *stacks, int location)
{
	int	temp;

	if (location == 'a' && stacks->a_len > 0)
	{
		temp = stacks->a[0];
		move_stack(stacks->a, stacks->a_len, 'u');
		stacks->a_len--;
		move_stack(stacks->b, stacks->b_len, 'd');
		stacks->b_len++;
		stacks->b[0] = temp;
		ft_putstr_fd("pa\n", 1);
	}
	if (location == 'b' && stacks->b_len > 0)
	{
		temp = stacks->b[0];
		move_stack(stacks->b, stacks->b_len, 'u');
		stacks->b_len--;
		move_stack(stacks->a, stacks->a_len, 'd');
		stacks->a_len++;
		ft_putstr_fd("pb\n", 1);
	}
}
