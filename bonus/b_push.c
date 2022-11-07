/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:32:24 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/07 17:35:36 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_push(t_bonus *bonus, int location)
{
	int	temp;

	if (location == 'a' && bonus->b_len > 0)
	{
		temp = bonus->b[0];
		move_stack(bonus->b, bonus->b_len, 'u');
		bonus->b_len--;
		bonus->a_len++;
		move_stack(bonus->a, bonus->a_len, 'd');
		bonus->a[0] = temp;
	}
	if (location == 'b' && bonus->a_len > 0)
	{
		temp = bonus->a[0];
		move_stack(bonus->a, bonus->a_len, 'u');
		bonus->a_len--;
		bonus->b_len++;
		move_stack(bonus->b, bonus->b_len, 'd');
		bonus->b[0] = temp;
	}
}
