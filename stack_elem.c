/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:45:42 by apimikov          #+#    #+#             */
/*   Updated: 2023/12/29 14:45:43 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	take_el(t_cstack stk, int i)
{
	int	pos;

	if (i >= 0)
		pos = (stk.head + i) % stk.maxn;
	else
		pos = (stk.tail + i + 1) % stk.maxn;
	return (stk.data[pos]);
}

int	*take_all(t_cstack stk, int *dat)
{
	int	pos;
	int	i;

	i = -1;
	pos = stk.head % stk.maxn;
	while (++i < stk.size)
		dat[i] = stk.data[(i + pos) % stk.maxn];
	return (dat);
}

int	position_in_stack(t_cstack a, int value)
{
	int	i;

	i = 0;
	while (i < a.size && value != take_el(a, i))
		i++;
	return (i);
}
