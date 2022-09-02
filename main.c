/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:08:51 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/02 16:04:25 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_free(t_stacks *stacks, char **array)
{
	int	i;

	i = -1;
	while (array[++i] != 0)
		free(array[i]);
	free(array);
	free(stacks->a);
	free(stacks->b);
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
	stacks->index = 0;
	stacks->grp_alen = 0;
	stacks->grp_blen = 0;
	stacks->sorted_stack_in_a = 0;
	stacks->sorted_stack_in_b = 0;
	stacks->merge_count = 0;
	stacks->recursion_count = 0;
	stacks->end_stack = 0;
	i = -1;
	while (++i < stacks->len)
		stacks->a[i] = ft_atoi(array[i]);
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
	check_stack(stacks);
	// end_stack_location(stacks);
	solve_stack(stacks);
	printf("Recursion Count = %d\n", stacks->recursion_count);
	print_numb(stacks);
	printf("------------------------------------------------\n");
	ft_free(stacks, array);
	free(stacks);
}
