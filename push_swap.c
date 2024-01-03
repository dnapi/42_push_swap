/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:02:28 by apimikov          #+#    #+#             */
/*   Updated: 2024/01/03 07:34:35 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	char		**arg_v;
	int			arg_c;
	char		*str;

	if (argc == 1)
		return (0);
	arg_v = argv;
	arg_c = argc;
	if (argc == 2 && ft_strchr(argv[1], (int) ' '))
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
	if (!is_sorted(stk.a))
		sort_circ(&stk, arg_c - 1);
	free_arg_v(argv, arg_v, arg_c);
	free_stack_duo(&stk);
	return (0);
}
