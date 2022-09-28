/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:17:53 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/28 23:23:26 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rotate_a(t_stacks *stacks)
{
	int	temp;

	temp = stacks->a[0];
	move_stack(stacks->a, stacks->a_len, 'u');
	stacks->a[stacks->a_len - 1] = temp;
}

void	rotate_b(t_stacks *stacks)
{
	int	temp;

	temp = stacks->b[0];
	move_stack(stacks->b, stacks->b_len, 'u');
	stacks->b[stacks->b_len - 1] = temp;
}

void	rotate(t_stacks *stacks, int heap)
{
	if (heap == 'a' && stacks->a_len > 1)
	{
		rotate_a(stacks);
		ft_putstr_fd("ra\n", 1);
	}
	else if (heap == 'b' && stacks->b_len > 1)
	{
		rotate_b(stacks);
		ft_putstr_fd("rb\n", 1);
	}
	else if (heap == 'r' && stacks->a_len > 1 && stacks->b_len > 1)
	{
		rotate_a(stacks);
		rotate_b(stacks);
		ft_putstr_fd("rr\n", 1);
	}
}
