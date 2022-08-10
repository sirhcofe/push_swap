/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:17:53 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/10 18:45:13 by chenlee          ###   ########.fr       */
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
	printf("THIS DID RUN");
}

void	rotate(t_stacks *stacks, int heap)
{
	if (heap == 'a')
		rotate_a(stacks);
}