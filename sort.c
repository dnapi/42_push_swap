/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:46:18 by apimikov          #+#    #+#             */
/*   Updated: 2023/12/30 14:53:25 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered_three(int x1, int x2, int x3)
{
	if (x1 < x2 && x2 < x3)
		return (1);
	return (0);
}

void	sort_two(t_circ_duo *stk)
{
	int	x0;
	int	x1;

	x0 = stk->a.data[stk->a.head];
	x1 = stk->a.data[(stk->a.head + 1) % stk->a.maxn];
	if (x0 > x1)
		sa(stk, 1);
	return ;
}

void	sort_three(t_circ_duo *stk)
{
	int	x[3];

	x[0] = stk->a.data[stk->a.head];
	x[1] = stk->a.data[(stk->a.head + 1) % stk->a.maxn];
	x[2] = stk->a.data[(stk->a.head + 2) % stk->a.maxn];
	if (is_ordered_three(x[0], x[2], x[1]))
	{
		sa(stk, 1);
		ra(stk, 1);
	}
	else if (is_ordered_three(x[1], x[0], x[2]))
		sa(stk, 1);
	else if (is_ordered_three(x[2], x[0], x[1]))
		rra(stk, 1);
	else if (is_ordered_three(x[1], x[2], x[0]))
		ra(stk, 1);
	else if (is_ordered_three(x[2], x[1], x[0]))
	{
		sa(stk, 1);
		rra(stk, 1);
	}
	return ;
}

void	sort_small(t_circ_duo *stk)
{
	int	size;
	int i;

	size = stk->a.size;
	while (stk->a.size > 3)
	{
		if (is_ordered_three(take_el(stk->a, 1), take_el(stk->a, 0) , size - 2))
			sa(stk, 1);
		if (take_el(stk->a, 0) < size - 2)
			pb(stk, 1);
		else
			ra(stk, 1);
	}
	sort_three(stk);
	i = stk->a.maxn - 3;
	while (i > 0)
		move_to_a_imp(stk, i--);
	return ;
}

void	sort_medium(t_circ_duo *stk)
{
	int	i;
	int	k;
	int c100;
	int c500;

	c100 = 25; // for 1000  25 -> max=674 
	c500 = 50; // for 1000  50 -> max=5257 | 75-> 5417 | 60 ->5289 | 65-> 5296 | 55=> 5312
	k = stk->a.maxn / (c100 + (stk->a.maxn - 100) * (c500 - c100) / 400);
	i = -1;
	while (++i < k)
		move_quart2b(stk, k, i);
	move_quart2b(stk, 1, 0);
	sort_three(stk);
	i = stk->a.maxn - 3;
	while (i > 0)
		move_to_a_imp(stk, i--);
	return ;
}
