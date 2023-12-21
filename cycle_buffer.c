#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_cstack
{
	int	*data;
	int	head;
	int	tail;
	int	maxn;
	int size;
}	t_cstack;

void	selection_sort(int arr[], int n); 

//remove this function and use libft
int	ft_atoi(const char *str)
{

//remove this function and use libft

	int			sign;
	long long	answ;
	long long	llong_max;

	llong_max = ((unsigned long long)(-1)) / 2;
	sign = 1;
	answ = 0;
	while ((8 < *str && *str < 14) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
	{
		if (answ > llong_max / 10)
			return ((sign > 0) * (-1));
		answ = answ * 10;
		if (answ > llong_max - (*str - '0'))
			return ((sign > 0) * (-1));
		answ = answ + ((*str++) - '0');
	}
	return ((int)(sign * answ));
}

int	read_cstack(t_cstack **stk, int argc, char **argv)
{
	int *dat;
	int	i;

	if (*stk)
		return (2);
	*stk = (t_cstack *)malloc(sizeof(t_cstack));
	if (!*stk)
		return (1);
	if (argc == 1)
		return (3);
	dat = (int *)malloc((argc - 1) * sizeof(int));
	if (!dat)
	{
		free(*stk);
		*stk = NULL;
		return (1);
	}
	i = -1;
	while (++i < argc - 1)
		dat[i] = ft_atoi(argv[i + 1]);
	(*stk)->data = dat;
	(*stk)->maxn = argc - 1;
	(*stk)->head = 0;
	(*stk)->tail = argc - 2;
	(*stk)->size = argc - 1;
	return (0);
}

//do you need this function???
int	init_cstack(t_cstack **stk, int size)
{
	int *dat;
	int	i;

	if (*stk)
		return (2);
	*stk = (t_cstack *)malloc(sizeof(t_cstack));
	if (!*stk)
		return (1);
	dat = (int *)malloc(size * sizeof(int));
	if (!dat)
	{
		free(*stk);
		*stk = NULL;
		return (1);
	}
	i = -1;
	while (i < size)
		dat[i++] = 0;
	(*stk)->data = dat;
	(*stk)->head = 0;
	(*stk)->tail = 0;
	(*stk)->size = 0;
	return (0);
}

// do I need this function ???
int	sort_full_stack(t_cstack **stk)
{

// do I need this function ???
	if (!*stk)
		return (1);
	selection_sort((*stk)->data, (*stk)->tail + 1);	
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

int	pop_cstack(t_cstack **p_stk)
{
	int	res;

	if ((*p_stk)->size == 0)
	{
		write(1, "Pop error!\n", 11);
		return (0);
	}
	res = (*p_stk)->data[(*p_stk)->head];
	(*p_stk)->data[(*p_stk)->head] = 0;
	if ((*p_stk)->head == (*p_stk)->tail)
	{
		(*p_stk)->head = 0;
		(*p_stk)->tail = 0;
		(*p_stk)->size = 0;
		return (res);
	}
	(*p_stk)->head = ((*p_stk)->head + 1) % (*p_stk)->maxn;
	(*p_stk)->size--;
	return (res);
}

int	floor_div(int num, int den)
{
	if (num > 0 % den > 0)
		return (num % den);
	if (num < 0 % den > 0)
		return (num % den + den);
}

int	push_cstack(t_cstack **p_stk, int num)
{
	if ((*p_stk)->size == (*p_stk)->maxn)
	{
		write(1, "Error push\n", 11); 
		return (1);
	}
	(*p_stk)->head = floor_div(((*p_stk)->head - 1), (*p_stk)->maxn);
	(*p_stk)->data[(*p_stk)->head] = num;
	(*p_stk)->size++;
	return (0);
}

int	rrot_cstack(t_cstack **p_stk)
{
	int temp;

	if ((*p_stk)->size == 0)
	{
		write(1, "Error reverse rotate empty stack\n", 33); 
		return (1);
	}
	temp = (*p_stk)->data[(*p_stk)->tail];
	(*p_stk)->data[(*p_stk)->tail] = 0;
	(*p_stk)->head = floor_div((*p_stk)->head - 1 , (*p_stk)->maxn);
	(*p_stk)->tail = floor_div((*p_stk)->tail - 1 , (*p_stk)->maxn);
	(*p_stk)->data[(*p_stk)->head] = temp;
	return (0);
}

int	rot_cstack(t_cstack **p_stk)
{
	int temp;

	if ((*p_stk)->size == 0)
	{
		write(1, "Error rotate empty stack\n", 25); 
		return (1);
	}
	temp = (*p_stk)->data[(*p_stk)->head];
	(*p_stk)->data[(*p_stk)->head] = 0;
	(*p_stk)->head = ((*p_stk)->head + 1) % (*p_stk)->maxn;
	(*p_stk)->tail = ((*p_stk)->tail + 1) % (*p_stk)->maxn;
	(*p_stk)->data[(*p_stk)->tail] = temp;
	return (0);
}

int	swap_cstack(t_cstack **p_stk)
{
	int temp;
	int second;

	if ((*p_stk)->size == 0)
	{
		write(1, "Error swap empty stack\n", 24); 
		return (1);
	}
	temp = (*p_stk)->data[(*p_stk)->head];
	second = ((*p_stk)->head + 1) % (*p_stk)->maxn;
	(*p_stk)->data[(*p_stk)->head] = (*p_stk)->data[second];
	(*p_stk)->data[second] = temp;	
	return (0);
}

void	print_cstack(t_cstack **p_stk)
{
	int max_size;
	int i;

	printf("\n----- stack -----\n");
	max_size = (*p_stk)->maxn;
	printf("\nmaxn=%d\n",max_size);
	printf("size=%d\n",(*p_stk)->size);
	printf("head=%d\n",(*p_stk)->head);
	printf("tail=%d\n",(*p_stk)->tail);
	printf("size calculated=%d\n",((*p_stk)->tail - (*p_stk)->head) % max_size + 1);

	i = -1;
	printf("\n  ------  \n");
	while (++i < max_size)
	{
		printf("%d",(*p_stk)->data[i]);
		if (i == (*p_stk)->head)
			printf("<-HEAD");
		if (i == (*p_stk)->tail)
			printf("<-TAIL");
		printf("\n");
	}
	printf("-----  end  -----\n\n");
}

int	replace_by_rank(t_cstack **p_stk, int size)
{
	int *dat;
	int temp[size];
	int	i;
	int	j;

	if ((*p_stk)->size != (*p_stk)->maxn)
		return (1);
	dat = (*p_stk)->data;
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

int main(int argc, char **argv)
{
	t_cstack	*stk;
	int			*arr;
	int			i;

	read_cstack(&stk, argc, argv);
	print_cstack(&stk);
//	sort_full_stack(&stk);
	replace_by_rank(&stk, argc - 1);
	print_cstack(&stk);
	printf("rot msg =%d\n", rrot_cstack(&stk));
	print_cstack(&stk);
	printf("swap msg=%d\n\n",swap_cstack(&stk)); 
	print_cstack(&stk);
	printf("pop value=%d\n\n",pop_cstack(&stk)); 
	printf("pop value=%d\n\n",pop_cstack(&stk)); 
	printf("pop value=%d\n\n",pop_cstack(&stk)); 
	print_cstack(&stk);
	printf("rot msg =%d\n", rrot_cstack(&stk));
	printf("rot msg =%d\n", rrot_cstack(&stk));
	print_cstack(&stk);
	printf("push error=%d\n\n",push_cstack(&stk, 20)); 
	printf("push error=%d\n\n",push_cstack(&stk, 21)); 
	printf("push error=%d\n\n",push_cstack(&stk, 22)); 
	printf("push error=%d\n\n",push_cstack(&stk, 23)); 
	print_cstack(&stk);
	printf("%d\n", (-23) % 10);
	printf("%d\n", floor_div(-23,10));
/*
	printf("push error=%d\n\n",push_cstack(&stk, 20)); 
	printf("push result=%d\n\n",push_cstack(&stk, 21)); 
	printf("push result=%d\n\n",push_cstack(&stk, 22)); 
	printf("push result=%d\n\n",push_cstack(&stk, 23)); 
	printf("pop value=%d\n\n",pop_cstack(&stk)); 
	print_cstack(&stk);
	printf("pop value=%d\n\n",pop_cstack(&stk)); 
	print_cstack(&stk);
	printf("pop value=%d\n\n",pop_cstack(&stk)); 
	printf("pop value=%d\n\n",pop_cstack(&stk)); 
	printf("pop value=%d\n\n",pop_cstack(&stk)); 
	print_cstack(&stk);
	printf("pop value=%d\n\n",pop_cstack(&stk)); 
	printf("pop value=%d\n\n",pop_cstack(&stk)); 
	printf("pop value=%d\n\n",pop_cstack(&stk)); 
	print_cstack(&stk);
*/
	return (0);
}

