/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:02:54 by apimikov          #+#    #+#             */
/*   Updated: 2024/01/03 07:02:58 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrot_cstack(t_cstack *p_stk)
{
	int	temp;

	if (p_stk->size == 0)
	{
		if (PRINTERRORS)
			write(1, "Error reverse rotate empty stack\n", 33);
		return (1);
	}
	if (p_stk->maxn == 1)
		return (0);
	temp = p_stk->data[p_stk->tail];
	p_stk->data[p_stk->tail] = 0;
	p_stk->head = floor_div(p_stk->head - 1, p_stk->maxn);
	p_stk->tail = floor_div(p_stk->tail - 1, p_stk->maxn);
	p_stk->data[p_stk->head] = temp;
	return (0);
}

int	rot_cstack(t_cstack *p_stk)
{
	int	temp;

	if (p_stk->size == 0)
	{
		if (PRINTERRORS)
			write(1, "Error rotate empty stack\n", 25);
		return (1);
	}
	if (p_stk->maxn == 1)
		return (0);
	temp = p_stk->data[p_stk->head];
	p_stk->data[p_stk->head] = 0;
	p_stk->head = (p_stk->head + 1) % p_stk->maxn;
	p_stk->tail = (p_stk->tail + 1) % p_stk->maxn;
	p_stk->data[p_stk->tail] = temp;
	return (0);
}
