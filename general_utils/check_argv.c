/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:03:52 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/20 19:03:59 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i] != 0)
	{
		j = 0;
		while (array[i][j] != 0)
		{
			if (!ft_isdigit(array[i][j]))
				error(2);
			j++;
		}
		i++;
	}
}
