/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:10:21 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/07 21:18:48 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "./libft/libft.h"

# define BUFFER_SIZE 4

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		*edge_case;
	int		len;
	int		a_len;
	int		b_len;
	int		grp_alen;
	int		grp_blen;
	int		mrg_cond;
	int		mrg_count;
	int		mrg_stack;
	int		sel_cond;
	int		b_rotate;
	int		sorted_a;
	int		sorted_b;
	int		end_stack;
}			t_stacks;

typedef struct s_bonus
{
	int	*a;
	int	*b;
	int	len;
	int	a_len;
	int	b_len;
}		t_bonus;

// general utils
char	**parse_cmd_argument(int argc, char **argv);
void	error(int condition);
void	error_check(char **array);
void	check_stack(t_stacks *stacks);
void	initiate_edge_case(t_stacks *stacks);
void	print_numb(t_bonus *stacks);
long	power_two(int count);
long	power_ten(int count);
int		check_edge_case(t_stacks *stacks, int size);
int		end_stack_location(long size);
int		ft_oddeven(int num);
int		get_power(int size);

// hard coded
void	solve_stack(t_stacks *stacks);
void	solve_two(t_stacks *stacks);
void	solve_three(t_stacks *stacks);
void	solve_five(t_stacks *stacks);

// mandatory - merge
void	merge_sort(t_stacks *stacks, int front, int middle, int rear);
void	continue_merge(t_stacks *stacks, int condition);


// mandatory - selection
void	selection_sort(t_stacks *stacks, int front, int rear);
void	selection_to_a(t_stacks *stacks, int size);
void	selection_to_b(t_stacks *stacks, int size);
void	plus_sel_stack(t_stacks *stacks, int stack, int size);
void	extra(t_stacks *stacks, int size, int condition);
int		rotate_or_not(t_stacks *stacks, int size, int stack);


// mandatory - instruction
void	move_stack(int *array, int size, int direction);
void	push(t_stacks *stacks, int location);
void	rotate(t_stacks *stacks, int heap);
void	r_rotate(t_stacks *stacks, int heap);
void	swap(t_stacks *stacks, int heap);

// bonus
void	check_solution(t_bonus *bonus);
char	*get_next_line(int fd);
void	b_push(t_bonus *bonus, int location);
void	b_rotate(t_bonus *bonus, int heap);
void	b_rrotate(t_bonus *bonus, int heap);
void	b_swap(t_bonus *bonus, int heap);

#endif