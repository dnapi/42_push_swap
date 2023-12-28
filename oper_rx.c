/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apmikov <apmikov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:24:52 by apmikov           #+#    #+#             */
/*   Updated: 2023/12/28 04:24:54 by apmikov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_circ_duo *stk, int print_flag)
{
	rot_cstack(&stk->a);
	if (print_flag)
		write(1, "ra\n", 3);
	return ;
}

void	rb(t_circ_duo *stk, int print_flag)
{
	rot_cstack(&stk->b);
	if (print_flag)
		write(1, "rb\n", 3);
	return ;
}

void	rr(t_circ_duo *stk, int print_flag)
{
	rot_cstack(&stk->a);
	rot_cstack(&stk->b);
	if (print_flag)
		write(1, "rr\n", 3);
	return ;
}
