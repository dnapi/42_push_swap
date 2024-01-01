/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:45:58 by apimikov          #+#    #+#             */
/*   Updated: 2023/12/31 09:14:32 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_quart2b(t_circ_duo *stk, int k, int i)
{
	int	num;
	int	count;

	num = (stk->a.maxn - 3) / k;
	count = 0;
	while (count < num && stk->a.size > 3)
	{
		if (is_ordered_three(0, take_el(stk->a, 0) - num * i, num + 1))
		{
			pb(stk, 1);
			count++;
		}
		else if (take_el(stk->b, 0) - i * num > num / 2)
			rr(stk, 1);
		else
			ra(stk, 1);
		if (take_el(stk->b, 0) < take_el(stk->b, 1) && take_el(stk->a, 0) > take_el(stk->a, 1))
			ss(stk, 1);
		if (take_el(stk->b, 0) < take_el(stk->b, 1))
			sb(stk, 1);
	}
}

void	do_magic_r(t_circ_duo *stk, int value, int flag)
{
	int	i;

	while (value != take_el(stk->b, 0))
	{
		if (take_el(stk->a, 0) > take_el(stk->b, 0) && (take_el(stk->a, -1) == stk->a.maxn || take_el(stk->a, -1) < take_el(stk->b, 0)))
			pa(stk, flag);
		else
		{
			i = position_in_stack(stk->b, value);
			if (i > stk->b.size / 2)
				rrb(stk, flag);
			else if (i > 0)
				rb(stk, flag);
		}
	}
	i = 0;
	while (take_el(stk->a, 0) != value + 1)
		ra(stk, flag);
}

void	move_to_a_imp(t_circ_duo *stk, int value)
{
	int	i;

	i = -1;
	while (++i < stk->b.size)
	{
		if (take_el(stk->b, i) == value)
			break ;
	}
	if (i == stk->b.size)
	{
		rra(stk, 1);
		return ;
	}
	do_magic_r(stk, value, 1);
	pa(stk, 1);
	return ;
}
