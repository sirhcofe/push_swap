/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:37 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/04 17:33:50 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
