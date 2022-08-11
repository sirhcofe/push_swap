/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:08:51 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/11 18:34:59 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void	initiate_stack(t_stacks *stacks, char **array)
{
	int		i;

	stacks->len = 0;
	while (array[stacks->len] != 0)
		stacks->len++;
	if (stacks->len == 1)
		error(3);
	stacks->a = ft_calloc(stacks->len, sizeof(int));
	stacks->b = ft_calloc(stacks->len, sizeof(int));
	stacks->a_len = stacks->len;
	stacks->b_len = 0;
	i = 0;
	while (i < stacks->len)
	{
		stacks->a[i] = ft_atoi(array[i]);
		i++;
	}
}

char	**parse_cmd_argument(int argc, char **argv)
{
	char	**array;
	char	*temp;
	int		i;

	array = NULL;
	temp = NULL;
	if (argc < 2)
		error(1);
	else if (argc == 2)
		array = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			temp = ft_strjoin(temp, argv[i]);
			temp = ft_strjoin(temp, " ");
			i++;
		}
		array = ft_split(temp, ' ');
		free(temp);
	}
	return (array);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**array;

	array = parse_cmd_argument(argc, argv);
	error_check(array);
	stacks = malloc(sizeof(t_stacks));
	initiate_stack(stacks, array);
	merge_sort(stacks, 0, stacks->a_len);
	// int	i = 0;
	// while (i < stacks->a_len)
	// {
	// 	printf("-%d-\n", stacks->a[i]);
	// 	i++;
	// }
}