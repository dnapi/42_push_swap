/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apmikov <apmikov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:19:35 by apmikov           #+#    #+#             */
/*   Updated: 2023/12/30 11:48:56 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// do I need this function ???
int	sort_full_stack(t_cstack *stk)
{
// do I need this function ???
	if (!stk)
		return (1);
	selection_sort(stk->data, stk->tail + 1);
	return (0);
}

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

	if (!p_stk)
		return (1);
	if (p_stk->size != p_stk->maxn)
		return (1);
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

/*
int	replace_by_rank(t_cstack *p_stk, int size)
{
	int *dat;
	int temp[size];
  // remove VLA
	int	i;
	int	j;

	if (p_stk->size != p_stk->maxn)
		return (1);
	dat = p_stk->data;
	i = -1;
	while (++i < size)
		temp[i] = dat[i];
	selection_sort(temp, size);
	while (--i >= 0)
	{
		j = -1;
		while (++j < size)
		{
			if (dat[i] == temp[j])
			{
				dat[i] = j + 1;
				break;
			}
		}
	}
	return (0);
}
  */
