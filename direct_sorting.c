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
	int minIndex;

	i = 0;
	while (i < n - 1)
	{
		minIndex = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
			j++;
		}
		swap(&arr[minIndex], &arr[i]);
		i++;
	}
}

int	replace_by_rank(t_cstack *p_stk, int size)
{
	int *dat;
	int temp[size];
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
