/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 06:57:10 by apimikov          #+#    #+#             */
/*   Updated: 2024/01/03 06:57:14 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
