/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:42:05 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/07 21:18:28 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_numb(t_bonus *stacks)
{
	int	i;

	i = 0;
	printf("---A---\n");
	while (i < stacks->a_len)
	{
		printf("%4d\n", stacks->a[i]);
		i++;
	}
	i = 0;
	printf("---B---\n");
	while (i < stacks->b_len)
	{
		printf("%4d\n", stacks->b[i]);
		i++;
	}
}
