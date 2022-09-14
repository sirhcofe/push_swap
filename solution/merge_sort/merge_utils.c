/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:27:08 by chenlee           #+#    #+#             */
/*   Updated: 2022/09/05 16:18:35 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cont_cond_one(t_stacks *stacks, int pos)
{
	if (pos == 0 || pos == 3 || pos == stacks->grp_blen)
	{
		push(stacks, 'b');
		if (pos == 3 || pos == stacks->grp_blen)
			rotate(stacks, 'b');
	}
	else if (pos == 1)
	{
		rotate(stacks, 'b');
		push(stacks, 'b');
		r_rotate(stacks, 'b');
	}
	else if (pos == 2)
	{
		r_rotate(stacks, 'b');
		push(stacks, 'b');
		rotate(stacks, 'b');
		rotate(stacks, 'b');
	}
}

void	final_merge(t_stacks *stacks, int condition, int position)
{
	int	i;

	if (condition == 1)
		cont_cond_one(stacks, position);
	else
	{
		i = -1;
		while (++i < position)
			rotate(stacks, 'b');
		push(stacks, 'b');
		while (--i != -1)
			r_rotate(stacks, 'b');
	}
	stacks->grp_blen++;
}

int	determine_pos(t_stacks *stacks, int condition)
{
	int	i;

	i = 0;
	if (condition == 1)
		while (i < stacks->grp_blen && stacks->a[0] > stacks->b[i])
			i++;
	else if (condition == 2)
		while (i < stacks->grp_blen && stacks->a[0] < stacks->b[i])
			i++;
	return (i);
}

/**
 * @brief
 * Swaps numbers where:  
 * Condition 1: swaps in ascending order;
 * Condition 2: swaps in descending order.
 */
void	swapping(t_stacks *stacks, int condition)
{
	if (condition == 1)
	{
		if (stacks->a[0] > stacks->a[1] && stacks->b[0] > stacks->b[1]
			&& stacks->grp_alen > 1 && stacks->grp_blen > 1)
			swap(stacks, 's');
		else if (stacks->a[0] > stacks->a[1] && stacks->grp_alen > 1)
			swap(stacks, 'a');
		else if (stacks->b[0] > stacks->b[1] && stacks->grp_blen > 1)
			swap(stacks, 'b');
	}
	else if (condition == 2)
	{
		if (stacks->a[0] < stacks->a[1] && stacks->b[0] < stacks->b[1]
			&& stacks->grp_alen > 1 && stacks->grp_blen > 1)
			swap(stacks, 's');
		else if (stacks->a[0] < stacks->a[1] && stacks->grp_alen > 1)
			swap(stacks, 'a');
		else if (stacks->b[0] < stacks->b[1] && stacks->grp_blen > 1)
			swap(stacks, 'b');
	}
}

void	continue_merge(t_stacks *stacks, int condition)
{
	int	i;
	int	pos;

	i = -1;
	while (++i < stacks->grp_blen)
		push(stacks, 'b');
	swapping(stacks, condition);
	i = -1;
	while (++i < stacks->grp_alen)
	{
		pos = determine_pos(stacks, condition);
		if (stacks->grp_blen == stacks->b_len)
			final_merge(stacks, 1, pos);
		else
			final_merge(stacks, 2, pos);
	}
}
