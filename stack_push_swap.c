/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apmikov <apmikov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:44:24 by apmikov           #+#    #+#             */
/*   Updated: 2023/12/28 04:44:26 by apmikov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	floor_div(int num, int den)
{
	if (num > 0 && den > 0)
		return (num % den);
	return ((num + den) % den);
}

int	pop_cstack(t_cstack *p_stk)
{
	int	res;

	if (p_stk->size == 0)
	{
		write(1, "Pop error!\n", 11);
		return (0);
	}
	res = p_stk->data[p_stk->head];
	p_stk->data[p_stk->head] = 0;
	if (p_stk->head == p_stk->tail)
	{
		p_stk->head = 0;
		p_stk->tail = 0;
		p_stk->size = 0;
		return (res);
	}
	p_stk->head = (p_stk->head + 1) % p_stk->maxn;
	p_stk->size--;
	return (res);
}

int	push_cstack(t_cstack *p_stk, int num)
{
	if (p_stk->size == p_stk->maxn)
	{
		write(1, "Error push\n", 11);
		return (1);
	}
	if (p_stk->maxn > 1 && p_stk->size > 0)
		p_stk->head = floor_div((p_stk->head - 1), p_stk->maxn);
	p_stk->data[p_stk->head] = num;
	p_stk->size++;
	return (0);
}

int	swap_cstack(t_cstack *p_stk)
{
	int	temp;
	int	second;

	if (p_stk->size == 0)
	{
		write(1, "Error swap empty stack\n", 24);
		return (1);
	}
	temp = p_stk->data[p_stk->head];
	second = (p_stk->head + 1) % p_stk->maxn;
	p_stk->data[p_stk->head] = p_stk->data[second];
	p_stk->data[second] = temp;
	return (0);
}
