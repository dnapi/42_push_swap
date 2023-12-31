/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_px_sx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:00:50 by apimikov          #+#    #+#             */
/*   Updated: 2024/01/03 07:00:54 by apimikov         ###   ########.fr       */
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
