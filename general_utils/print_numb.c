/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:42:05 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/26 05:48:18 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_numb(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a_len)
	{
		printf("%4d\n", stacks->a[i]);
		i++;
	}
	i = 0;
	while (i < stacks->b_len)
	{
		printf("%4d\n", stacks->b[i]);
		i++;
	}
}