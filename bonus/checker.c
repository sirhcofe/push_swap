/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:56:55 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/07 21:27:19 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	if (ft_strlen(str1) != ft_strlen(str2))
		return (1);
	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_execute_input(t_bonus *bonus, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		b_push(bonus, 'a');
	else if (ft_strcmp(str, "pb\n") == 0)
		b_push(bonus, 'b');
	else if (ft_strcmp(str, "sa\n") == 0)
		b_swap(bonus, 'a');
	else if (ft_strcmp(str, "sb\n") == 0)
		b_swap(bonus, 'b');
	else if (ft_strcmp(str, "ss\n") == 0)
		b_swap(bonus, 's');
	else if (ft_strcmp(str, "ra\n") == 0)
		b_rotate(bonus, 'a');
	else if (ft_strcmp(str, "rb\n") == 0)
		b_rotate(bonus, 'b');
	else if (ft_strcmp(str, "rr\n") == 0)
		b_rotate(bonus, 'r');
	else if (ft_strcmp(str, "rra\n") == 0)
		b_rrotate(bonus, 'a');
	else if (ft_strcmp(str, "rrb\n") == 0)
		b_rrotate(bonus, 'b');
	else if (ft_strcmp(str, "rrr\n") == 0)
		b_rrotate(bonus, 'r');
	else
		return (1);
	return (0);
}

#include <stdio.h>
void	check_solution(t_bonus *bonus)
{
	char	*input;
	(void)bonus;

	while (1)
	{
		input = get_next_line(0);
		if (input == NULL || ft_strcmp(input, "\n") == 0)
			break ;
		else if (check_execute_input(bonus, input) == 1)
			error(6);
	}
}