/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:10:21 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/01 20:58:17 by chenlee          ###   ########.fr       */
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
	int		len;
	int		a_len;
	int		b_len;
	int		index;
	int		recursion_count;
	int		grp_alen;
	int		grp_blen;
	int		sorted_stack_in_a;
	int		sorted_stack_in_b;
	int		merge_count;
	int		end_stack;
}			t_stacks;

void	error(int condition);
void	error_check(char **array);
void	check_stack(t_stacks *stacks);
void	print_numb(t_stacks *stacks);

void	solve_stack(t_stacks *stacks);
void	solve_two(t_stacks *stacks);
void	solve_three(t_stacks *stacks);

void	merge_sort(t_stacks *stacks, int front, int middle, int rear);
void	continue_merge(t_stacks *stacks, int condition);

void	selection_sort(t_stacks *stacks, int size, int rear);
void	selection_to_a(t_stacks *stacks, int size);
void	selection_to_b(t_stacks *stacks, int size);

void	move_stack(int *array, int size, int direction);
void	push(t_stacks *stacks, int location);
void	rotate(t_stacks *stacks, int heap);
void	r_rotate(t_stacks *stacks, int heap);
void	swap(t_stacks *stacks, int heap);

#endif