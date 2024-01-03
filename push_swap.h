/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:07:23 by apimikov          #+#    #+#             */
/*   Updated: 2024/01/03 07:37:22 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define PRINTERRORS 0

typedef struct s_cstack
{
	int	*data;
	int	head;
	int	tail;
	int	maxn;
	int	size;
}	t_cstack;

typedef struct s_circ_duo
{
	t_cstack	a;
	t_cstack	b;
}	t_circ_duo;

void	selection_sort(int arr[], int n);

// libft_mod.c
long	ft_atoil(const char *str);
char	*ft_strjoin_mod(char const *s1, char const *s2, char c);

// make_stack.c
int		read_cstack(t_cstack *stk, int argc, char **argv);
int		init_cstack(t_cstack *stk, int size);
int		make_stack(t_circ_duo *stk, int arg, char **argv);
int		is_sorted(t_cstack a);

// direct_sorting.c
void	swap(int *a, int *b);
void	selection_sort(int arr[], int n);
int		replace_by_rank(t_cstack *p_stk, int size);

// stack_push_swap.c
int		floor_div(int num, int den);
int		pop_cstack(t_cstack *p_stk);
int		push_cstack(t_cstack *p_stk, int num);
int		swap_cstack(t_cstack *p_stk);

// stack_rotate.c
int		rrot_cstack(t_cstack *p_stk);
int		rot_cstack(t_cstack *p_stk);

// oper_px_sx.c
void	pb(t_circ_duo *stk, int print_flag);
void	pa(t_circ_duo *stk, int print_flag);
void	sa(t_circ_duo *stk, int print_flag);
void	sb(t_circ_duo *stk, int print_flag);
void	ss(t_circ_duo *stk, int print_flag);

// oper_rx.c
void	ra(t_circ_duo *stk, int print_flag);
void	rb(t_circ_duo *stk, int print_flag);
void	rr(t_circ_duo *stk, int print_flag);

// oper_rrx.c
void	rra(t_circ_duo *stk, int print_flag);
void	rrb(t_circ_duo *stk, int print_flag);
void	rrr(t_circ_duo *stk, int print_flag);

// check_args.c
void	print_cstack(t_cstack *p_stk);
void	print_duo_cstack(t_circ_duo stk);
int		error_w(int condition);
int		check_args(int argc, char **argv);

// sort.c
int		is_ordered_three(int x1, int x2, int x3);
void	sort_two(t_circ_duo *stk);
void	sort_three(t_circ_duo *stk);
void	sort_small(t_circ_duo *stk);
void	sort_medium(t_circ_duo *stk);

// sort_fun.c
void	move_quart2b(t_circ_duo *stk, int k, int i);
void	do_magic_r(t_circ_duo *stk, int value, int flag);
void	move_to_a_imp(t_circ_duo *stk, int value);

// stack_elem.c
int		take_el(t_cstack stk, int i);
int		*take_all(t_cstack stk, int *dat);
int		position_in_stack(t_cstack a, int value);

#endif
