/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 06:57:40 by apimikov          #+#    #+#             */
/*   Updated: 2024/01/03 07:50:02 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	selection_sort(int arr[], int n)
{
	int	i;
	int	j;
	int	min_index;

	i = 0;
	while (i < n - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_index])
				min_index = j;
			j++;
		}
		swap(&arr[min_index], &arr[i]);
		i++;
	}
}

int	*copy_array(int *data, int size)
{
	int	*dat;
	int	i;

	dat = (int *)malloc(size * sizeof(int));
	if (!dat)
		return (NULL);
	i = -1;
	while (++i < size)
		dat[i] = data[i];
	return (dat);
}

int	replace_by_rank(t_cstack *p_stk, int size)
{
	int	*temp;
	int	i;
	int	j;

	temp = copy_array(p_stk->data, p_stk->maxn);
	if (!temp)
		return (1);
	selection_sort(temp, size);
	i = size;
	while (--i >= 0)
	{
		j = -1;
		while (++j < size)
		{
			if (p_stk->data[i] == temp[j])
			{
				p_stk->data[i] = j + 1;
				break ;
			}
		}
	}
	free(temp);
	temp = NULL;
	return (0);
}
