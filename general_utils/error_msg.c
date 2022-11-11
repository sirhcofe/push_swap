/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:22:29 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/11 15:59:13 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int condition)
{
	if (condition == 1)
		ft_putstr_fd("Error: Expected more than 1 argument count\n", 1);
	else if (condition == 2)
		ft_putstr_fd("Error: Please provide only integers!\n", 1);
	else if (condition == 3)
	{
		ft_putstr_fd("Already sorted!\n", 1);
		exit(0);
	}
	else if (condition == 4)
		ft_putstr_fd("Error: No duplicates!\n", 1);
	else if (condition == 5)
		ft_putstr_fd("Error: Exceed MAX_INT/MIN_INT!\n", 1);
	else if (condition == 6)
	{
		ft_putstr_fd("Error: Invalid Input", 1);
		exit(1);
	}
	else if (condition == 7)
		ft_putstr_fd("KO\n", 1);
	else if (condition == 8)
		ft_putstr_fd("Error\n", 1);
	exit(0);
}
