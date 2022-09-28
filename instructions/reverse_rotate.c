/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:26:12 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/28 23:23:20 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_stacks *stacks)
{
	int	temp;

	temp = stacks->a[stacks->a_len - 1];
	move_stack(stacks->a, stacks->a_len, 'd');
	stacks->a[0] = temp;
}

void	r_rotate_b(t_stacks *stacks)
{
	int	temp;

	temp = stacks->b[stacks->b_len - 1];
	move_stack(stacks->b, stacks->b_len, 'd');
	stacks->b[0] = temp;
}

void	r_rotate(t_stacks *stacks, int heap)
{
	if (heap == 'a' && stacks->a_len > 1)
	{
		r_rotate_a(stacks);
		ft_putstr_fd("rra\n", 1);
	}
	else if (heap == 'b' && stacks->b_len > 1)
	{
		r_rotate_b(stacks);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (heap == 'r' && stacks->a_len > 1 && stacks->b_len > 1)
	{
		r_rotate_a(stacks);
		r_rotate_b(stacks);
		ft_putstr_fd("rrr\n", 1);
	}
}
