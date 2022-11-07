/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:35:00 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/07 20:35:28 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_rotate_a(t_bonus *bonus)
{
	int	temp;

	temp = bonus->a[0];
	move_stack(bonus->a, bonus->a_len, 'u');
	bonus->a[bonus->a_len - 1] = temp;
}

void	b_rotate_b(t_bonus *bonus)
{
	int	temp;

	temp = bonus->b[0];
	move_stack(bonus->b, bonus->b_len, 'u');
	bonus->b[bonus->b_len - 1] = temp;
}

void	b_rotate(t_bonus *bonus, int heap)
{
	if (heap == 'a' && bonus->a_len > 1)
		b_rotate_a(bonus);
	else if (heap == 'b' && bonus->b_len > 1)
		b_rotate_b(bonus);
	else if (heap == 'r' && bonus->a_len > 1 && bonus->b_len > 1)
	{
		b_rotate_a(bonus);
		b_rotate_b(bonus);
	}
}
