/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apmikov <apmikov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:42:11 by apmikov           #+#    #+#             */
/*   Updated: 2023/12/28 04:42:14 by apmikov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	is_ordered_list(int *x, int size)
{
	int	i;

	i = 0;
	while (x[i] < x[i + 1] && i < size - 1)
		i++;
	if (i == size - 1)
		return (1);
	return (0);
}
*/

/*
void	repeat_f(void (*f)(t_circ_duo *, int), int n, t_circ_duo *stk, int i)
{
	while (n-- > 0)
		f(stk, i);
}

void	move_to_a(t_circ_duo *stk, int value)
{
	int	i;
	int	size;

	i = -1;
	size = stk->b.size;
	while (++i < size)
		if (take_el(stk->b, i) == value)
			break ;
	if (i == size)
		return ;
	if (i > size / 2)
		repeat_f(rrb, size - i, stk, 1);
	else if (i > 0)
		repeat_f(rb, i, stk, 1);
	pa(stk, 1);
	return ;
}
*/

void	sort_circ(t_circ_duo *stk, int n)
{
	if (n == 2)
		sort_two(stk);
	else if (n == 3)
		sort_three(stk);
	else if (n < 10)
		sort_small(stk);
	else
		sort_medium(stk);
	return ;
}

void	free_stack_duo(t_circ_duo *stk)
{
	free(stk->a.data);
	stk->a.data = NULL;
	free(stk->b.data);
	stk->b.data = NULL;
}

int	main(int argc, char **argv)
{
	t_circ_duo	stk;

	//remove printf !
	//remove stdio in header
	if (check_args(argc, argv))
		return (1);
	if (make_stack(&stk, argc, argv))
		return (error_w(1));
	replace_by_rank(&stk.a, argc - 1);
	if (is_sorted(stk.a))
	{
		free_stack_duo(&stk);
		return (0);
	}
	sort_circ(&stk, argc - 1);
	free(stk.a.data);
	stk.a.data = NULL;
	free(stk.b.data);
	stk.b.data = NULL;
	return (0);
}
