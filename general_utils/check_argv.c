/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:03:52 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/28 23:28:17 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(char **array)
{
	int	i;
	int	j;
	int	neg;

	i = 0;
	while (array[i] != 0)
	{
		j = 0;
		neg = 0;
		while (array[i][j] != 0)
		{
			if (array[i][0] == '-' || array[i][0] == '+')
			{
				if (neg == 1 || !ft_isdigit(array[i][1]))
					error(2);
				neg++;
				j++;
			}
			else if (!ft_isdigit(array[i][j]))
				error(2);
			j++;
		}
		i++;
	}
}
