/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apmikov <apmikov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:58:08 by apmikov           #+#    #+#             */
/*   Updated: 2023/12/28 03:59:14 by apmikov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicated(t_cstack a);

int	make_stack(t_circ_duo *stk, int argc, char **argv)
{
	t_cstack	a;
	t_cstack	b;

	if (read_cstack(&a, argc, argv))
		return (1);
	if (is_duplicated(a))
		return (1);
	if (init_cstack(&b, argc - 1))
		return (1);
	stk->a = a;
	stk->b = b;
	return (0);
}

int	is_duplicated(t_cstack a)
{
	int	i;
	int	j;

	i = 0;
	while (++i < a.maxn)
	{
		j = -1;
		while (++j < i)
		{
			if (a.data[i] == a.data[j])
				return (1);
		}
	}
	return (0);
}

int	read_cstack(t_cstack *stk, int argc, char **argv)
{
	int		i;
	long long	t;

	if (!stk || argc == 1)
		return (1);
	stk->data = (int *)malloc((argc - 1) * sizeof(int));
	if (!stk->data)
		return (1);
	i = -1;
	while (++i < argc - 1)
	{
		t = ft_atoi(argv[i + 1]);
		if (t > 2147483647 || t < -2147483648 || ft_strlen(argv[i + 1]) > 10)
		{
			free(stk->data);
			return (1);
		}
		stk->data[i] = (int)t;
	}
	stk->maxn = argc - 1;
	stk->head = 0;
	stk->tail = argc - 2;
	stk->size = argc - 1;
	return (0);
}

int	init_cstack(t_cstack *stk, int size)
{
	int	*dat;
	int	i;

	if (!stk || size < 1)
		return (1);
	dat = (int *)malloc(size * sizeof(int));
	if (!dat)
		return (1);
	i = -1;
	while (i < size)
		dat[i++] = 0;
	stk->data = dat;
	stk->maxn = size;
	stk->size = 0;
	stk->head = 0;
	stk->tail = 0;
	stk->size = 0;
	return (0);
}