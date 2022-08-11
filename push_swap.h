/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:10:21 by chenlee           #+#    #+#             */
/*   Updated: 2022/08/11 13:28:33 by chenlee          ###   ########.fr       */
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
	char	*commands;
}			t_stacks;

void	error(int condition);

void	move_stack(int *array, int size, int direction);
void	push(t_stacks *stacks, int location);
void	rotate(t_stacks *stacks, int heap);
void	r_rotate(t_stacks *stacks, int heap);
void	swap(t_stacks *stacks, int heap);

#endif