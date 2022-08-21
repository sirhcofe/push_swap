/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:59:23 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/20 19:04:42 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
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