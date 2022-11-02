/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:22:29 by chenlee           #+#    #+#             */
/*   Updated: 2022/10/31 14:07:23 by chenlee          ###   ########.fr       */
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
	exit(0);
}
