/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apmikov <apmikov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:12:20 by apmikov           #+#    #+#             */
/*   Updated: 2023/12/31 08:07:14 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cstack(t_cstack *p_stk)
{
	int	max_size;
	int	i;

// rename printf to ft_printf or remove the functions before submission
	printf("\n\n\n----- stack -----\n");
	max_size = p_stk->maxn;
	printf("\nmaxn=%d\n", max_size);
	printf("size=%d\n", p_stk->size);
	printf("head=%d\n", p_stk->head);
	printf("tail=%d\n", p_stk->tail);
	if (max_size > 0)
		printf("check size=%d\n", (p_stk->tail - p_stk->head) % max_size + 1);
	i = -1;
	printf("\n  ------  \n");
	while (++i < max_size)
	{
		printf("%d", p_stk->data[i]);
		if (i == p_stk->head)
			printf("<-HEAD");
		if (i == p_stk->tail)
			printf("<-TAIL");
		printf("\n");
	}
	printf("-----  end  -----\n\n\n");
}

void	print_duo_cstack(t_circ_duo stk)
{
	int	i;
	int	pos;

	i = -1;
	printf("\n------------\n");
	printf("a\tb");
	printf("\n------------\n");
	while (++i < stk.a.maxn)
	{
		pos = (stk.a.head + i) % stk.a.maxn;
		printf("%d\t", stk.a.data[pos]);
		pos = (stk.b.head + i) % stk.b.maxn;
		printf("%d\n", stk.b.data[pos]);
	}
	printf("------------\n");
	return ;
}

int	error_w(int condition)
{
	if (condition)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (error_w(argc < 2))
		return (1);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		if (error_w(!ft_strchr("0987654321+-", (int)argv[i][++j])))
			return (1);
		while (argv[i][++j])
		{
			if (error_w(!ft_strchr("0987654321", argv[i][j])))
				return (1);
		}
		if (j == 1 && (argv[i][j - 1] == '+' || argv[i][j - 1] == '-'))
			return (error_w(1));
	}
	return (0);
}
