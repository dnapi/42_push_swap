/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rrx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:01:27 by apimikov          #+#    #+#             */
/*   Updated: 2024/01/03 07:01:30 by apimikov         ###   ########.fr       */
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
