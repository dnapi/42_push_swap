/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apmikov <apmikov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:42:11 by apmikov           #+#    #+#             */
/*   Updated: 2023/12/31 09:19:01 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		if (take_el(stk->b, i) == value)
			break ;
	}
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
	if (stk->a.data)
		free(stk->a.data);
	stk->a.data = NULL;
	if (stk->b.data)
		free(stk->b.data);
	stk->b.data = NULL;
}
	
int	free_arg_v(char **argv, char **arg_v, int arg_c)
{
	if (arg_v != argv)
		clean_array(&arg_v, arg_c + 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_circ_duo	stk;
	char 		**arg_v;
	int			arg_c;
	char		*str;

	//remove printf !
	//remove stdio in header
	if (argc == 1)
		return (0);
	arg_v = argv;
	arg_c = argc;
	if (argc == 2 && ft_strchr(argv[1], (int)' '))
	{
		str = ft_strjoin_mod(argv[0], argv[1], ' ');
		arg_v = ft_split(str, ' ');
		arg_c = (int)word_count_char(argv[1], ' ') + 1;
		free(str);
	}
	if (check_args(arg_c, arg_v))
		return (free_arg_v(argv, arg_v, arg_c));
	if (make_stack(&stk, arg_c, arg_v))
		return (error_w(free_arg_v(argv, arg_v, arg_c)));
//	print_duo_cstack(stk);
	if (!is_sorted(stk.a))
		sort_circ(&stk, arg_c - 1);
	free_arg_v(argv, arg_v, arg_c);
	free_stack_duo(&stk);
	return (0);
}

