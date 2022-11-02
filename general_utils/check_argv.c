/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:03:52 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/01 13:48:27 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	continue_error_check(char **array, int i)
{
	int	j;
	int	neg;

	j = 0;
	neg = 0;
	while (array[i][j] != 0)
	{
		if (j == 0 && (array[i][0] == '-' || array[i][0] == '+'))
		{
			if (neg == 1 && !ft_isdigit(array[i][1]))
				error(2);
			neg++;
			j++;
		}
		if (!ft_isdigit(array[i][j]))
			error(2);
		j++;
	}
}

void	error_check(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		if (ft_atoi(array[i]) > 2147483647 || ft_atoi(array[i]) < -2147483648)
			error(2);
		else
			continue_error_check(array, i);
		i++;
	}
}
