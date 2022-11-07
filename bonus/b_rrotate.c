/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:35:46 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/07 17:38:22 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_rrotate_a(t_bonus *bonus)
{
	int	temp;

	temp = bonus->a[bonus->a_len - 1];
	move_stack(bonus->a, bonus->a_len, 'd');
	bonus->a[0] = temp;
}

void	b_rrotate_b(t_bonus *bonus)
{
	int	temp;

	temp = bonus->b[bonus->b_len - 1];
	move_stack(bonus->b, bonus->b_len, 'd');
	bonus->b[0] = temp;
}

void	b_rrotate(t_bonus *bonus, int heap)
{
	if (heap == 'a' && bonus->a_len > 1)
		b_rrotate_a(bonus);
	else if (heap == 'b' && bonus->b_len > 1)
		b_rrotate_b(bonus);
	else if (heap == 'r' && bonus->a_len > 1 && bonus->b_len > 1)
	{
		b_rrotate_a(bonus);
		b_rrotate_b(bonus);
	}
}
