/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:59:23 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/04 18:35:37 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stacks *stacks)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stacks->a_len - 1)
	{
		j = i;
		while (++j < stacks->a_len)
		{
			if (stacks->a[i] == stacks->a[j])
				error(4);
		}
	}
}

void	check_is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (stacks->len == 1)
		error(3);
	while (i < stacks->a_len - 1)
	{
		if (stacks->a[i] < stacks->a[i + 1])
			i++;
		else
			break ;
	}
	if (i == stacks->a_len - 1)
		error(3);
}

void	check_stack(t_stacks *stacks)
{
	check_is_sorted(stacks);
	check_duplicates(stacks);
}
