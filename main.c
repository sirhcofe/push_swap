/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:08:51 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/28 23:19:59 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	stacks->grp_alen = 0;
	stacks->grp_blen = 0;
	stacks->mrg_cond = 0;
	stacks->mrg_count = 0;
	stacks->mrg_stack = 0;
	stacks->sel_cond = 0;
	stacks->b_rotate = 0;
	stacks->sorted_a = 0;
	stacks->sorted_b = 0;
	stacks->end_stack = 0;
	initiate_edge_case(stacks);
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
	stacks->end_stack = end_stack_location((long)stacks->a_len);
	solve_stack(stacks);
	ft_free(stacks, array);
	free(stacks);
}
