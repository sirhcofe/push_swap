/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:10:21 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/21 21:20:44 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int 	len;
	int		a_len;
	int		b_len;
	int		index;
	int		fhalf_location;
	int		shalf_location;
}			t_stacks;

void	error(int condition);
void	error_check(char **array);
void	check_if_sorted(t_stacks *stacks);
void	print_numb(t_stacks *stacks);

void	solve_stack(t_stacks *stacks);
void	solve_three(t_stacks *stacks);
void	merge_sort(t_stacks *stacks, int front, int middle, int rear);
void    selection_sort(t_stacks *stacks, int front, int middle, int rear);

void	move_stack(int *array, int size, int direction);
void	push(t_stacks *stacks, int location);
void	rotate(t_stacks *stacks, int heap);
void	r_rotate(t_stacks *stacks, int heap);
void	swap(t_stacks *stacks, int heap);

#endif