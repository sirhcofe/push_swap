/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_location.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:56:55 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/24 19:43:14 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	end_stack_location(long size)
{
	int	i;

	i = 0;
	while (!(power_two(i) + 1 <= size && size <= power_two(i + 1)))
		i++;
	if (ft_oddeven(i) == 0)
		return (0);
	else
		return (1);
}
