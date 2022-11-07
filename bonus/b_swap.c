/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:38:34 by chenlee           #+#    #+#             */
/*   Updated: 2022/11/07 20:35:09 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_swap_a(t_bonus *bonus)
{
	int	temp;

	temp = bonus->a[0];
	bonus->a[0] = bonus->a[1];
	bonus->a[1] = temp;
}

void	b_swap_b(t_bonus *bonus)
{
	int	temp;

	temp = bonus->b[0];
	bonus->b[0] = bonus->b[1];
	bonus->b[1] = temp;
}

void	b_swap(t_bonus *bonus, int heap)
{
	if (heap == 'a' && bonus->a_len > 1)
		b_swap_a(bonus);
	else if (heap == 'b' && bonus->b_len > 1)
		b_swap_b(bonus);
	else if (heap == 's' && bonus->a_len > 1 && bonus->b_len > 1)
	{
		b_swap_a(bonus);
		b_swap_b(bonus);
	}
}
