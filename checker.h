/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 06:45:10 by apimikov          #+#    #+#             */
/*   Updated: 2024/01/01 06:45:12 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# define PA 0
# define PB 1
# define SA 2
# define SB 3
# define SS 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define INDERROR 11

typedef void	(*t_oper_stk)(t_circ_duo *, int);

void	init_oper(char p_str[][5]);
int		oper_id(char *str, t_circ_duo *p_stk);
int		is_sorted_duo(t_circ_duo stk);
#endif
