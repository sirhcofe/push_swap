/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:06:19 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/10 18:08:29 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	int	temp;

	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
}

void	swap_b(t_stacks *stacks)
{
	int	temp;

	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
}

void	swap(t_stacks *stacks, int heap)
{
	if (heap == 'a' && stacks->a_len > 1)
		swap_a(stacks);
	else if (heap == 'b' && stacks->b_len > 1)
		swap_b(stacks);
	else if (heap == 'b' && stacks->a_len > 1 && stacks->b_len > 1)
	{
		swap_a(stacks);
		swap_b(stacks);
	}
}
