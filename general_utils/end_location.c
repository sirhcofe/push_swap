/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:56:55 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/12 20:21:30 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_stack_location(t_stacks *stacks)
{
	if ((ft_oddeven(stacks->a_len / 8) == 0 && stacks->a_len % 8 != 0)
		|| (ft_oddeven(stacks->a_len / 8) == 1 && stacks->a_len % 8 == 0))
		stacks->end_stack = 0;
	else
		stacks->end_stack = 1;
}
