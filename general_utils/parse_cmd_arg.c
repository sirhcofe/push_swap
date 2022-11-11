/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:33:37 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/11 16:35:51 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*continue_parse(int argc, char **argv)
{
	char	*str;
	int		i;

	str = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], """", 2) == 0)
			error(2);
		str = ft_strjoin(str, argv[i], 2);
		str = ft_strjoin(str, " ", 2);
		i++;
	}
	return (str);
}

char	**parse_cmd_argument(int argc, char **argv)
{
	char	**array;
	char	*str;

	array = NULL;
	if (argc < 2)
		error(1);
	else if (argc == 2)
	{
		if (ft_strncmp(argv[1], """", 2) == 0)
			error(2);
		else
			array = ft_split(argv[1], ' ');
	}
	else if (argc > 2)
	{
		str = continue_parse(argc, argv);
		array = ft_split(str, ' ');
		free(str);
	}
	return (array);
}
