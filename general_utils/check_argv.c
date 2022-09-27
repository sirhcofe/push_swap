/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:03:52 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/26 16:56:51 by chenlee          ###   ########.fr       */
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
			if (array[i][0] == '-')
			{
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
