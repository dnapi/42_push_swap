/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rrx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apmikov <apmikov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:25:20 by apmikov           #+#    #+#             */
/*   Updated: 2023/12/28 04:25:22 by apmikov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_circ_duo *stk, int print_flag)
{
	rrot_cstack(&stk->a);
	if (print_flag)
		write(1, "rra\n", 4);
	return ;
}

void	rrb(t_circ_duo *stk, int print_flag)
{
	rrot_cstack(&stk->b);
	if (print_flag)
		write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_circ_duo *stk, int print_flag)
{
	rrot_cstack(&stk->a);
	rrot_cstack(&stk->b);
	if (print_flag)
		write(1, "rrr\n", 4);
	return ;
}
