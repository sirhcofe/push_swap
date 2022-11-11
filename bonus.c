/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:28:59 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/11 16:35:39 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_bonus(t_bonus *bonus, char **array)
{
	int	i;

	i = -1;
	while (array[++i] != 0)
		free(array[i]);
	free(array);
	free(bonus->a);
	free(bonus->b);
}

void	initiate_bonus(t_bonus *bonus, char **array)
{
	int	i;

	bonus->len = 0;
	while (array[bonus->len] != 0)
		bonus->len++;
	bonus->a_len = bonus->len;
	bonus->b_len = 0;
	bonus->a = ft_calloc(bonus->len, sizeof(int));
	bonus->b = ft_calloc(bonus->len, sizeof(int));
	i = -1;
	while (++i < bonus->len)
		bonus->a[i] = (int)ft_atoi(array[i]);
}

void	check_duplicate(t_bonus *bonus)
{
	int	i;
	int	j;

	i = -1;
	while (++i < bonus->len - 1)
	{
		j = i;
		while (++j < bonus->len)
		{
			if (bonus->a[i] == bonus->a[j])
				error(4);
		}
	}
}

int	check_sorted(t_bonus *bonus)
{
	int	i;

	i = 0;
	if (bonus->len == 1)
		return (0);
	while (i < bonus->len - 1)
	{
		if (bonus->a[i] < bonus->a[i + 1])
			i++;
		else
			break ;
	}
	if (i == bonus->len - 1 && bonus->b_len == 0)
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	t_bonus	*bonus;
	char	**array;

	array = parse_cmd_argument(argc, argv);
	error_check(array);
	bonus = malloc(sizeof(t_bonus));
	initiate_bonus(bonus, array);
	check_duplicate(bonus);
	check_solution(bonus);
	if (check_sorted(bonus) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_bonus(bonus, array);
	free(bonus);
	return (0);
}
