/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_px_sx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apmikov <apmikov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:24:20 by apmikov           #+#    #+#             */
/*   Updated: 2023/12/28 04:24:22 by apmikov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_circ_duo *stk, int print_flag)
{
	push_cstack(&stk->b, pop_cstack(&stk->a));
	if (print_flag)
		write(1, "pb\n", 3);
	return ;
}

void	pa(t_circ_duo *stk, int print_flag)
{
	push_cstack(&stk->a, pop_cstack(&stk->b));
	if (print_flag)
		write(1, "pa\n", 3);
	return ;
}

void	sa(t_circ_duo *stk, int print_flag)
{
	swap_cstack(&stk->a);
	if (print_flag)
		write(1, "sa\n", 3);
	return ;
}

void	sb(t_circ_duo *stk, int print_flag)
{
	swap_cstack(&stk->b);
	if (print_flag)
		write(1, "sb\n", 3);
	return ;
}

void	ss(t_circ_duo *stk, int print_flag)
{
	swap_cstack(&stk->a);
	swap_cstack(&stk->b);
	if (print_flag)
		write(1, "ss\n", 3);
	return ;
}
