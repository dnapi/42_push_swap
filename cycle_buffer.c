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

typedef struct	s_cstack2
{
	t_cstack a;
	t_cstack b;
}	t_cstack2;

void	selection_sort(int arr[], int n); 

// remove and use one from libft
int	ft_atoi(const char *str)
{
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

	if (!stk || argc == 1)
		return (2);
	*stk = (t_cstack *)malloc(sizeof(t_cstack));
	if (!*stk)
		return (1);
	dat = (int *)malloc((argc - 1) * sizeof(int));
	if (!dat)
	{
		free(*stk);
		*stk = NULL;
		return (1);
	}
	if (*stk || argc == 1)
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

/*
int	read_cstack(t_cstack **stk, int argc, char **argv)
{
	int *dat;
	int	i;

	printf("ok\n");
	if (*stk || argc == 1)
		return (2);
	*stk = (t_cstack *)malloc(sizeof(t_cstack));
	if (!*stk)
		return (1);
	dat = (int *)malloc((argc - 1) * sizeof(int));
	if (!dat)
	{
		free(*stk);
		*stk = NULL;
		return (1);
	}
	if (*stk || argc == 1)
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
*/

//do you need this function???
int	init_cstack(t_cstack **stk, int size)
{
	int *dat;
	int	i;

	if (!stk)
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
	(*stk)->maxn = size;
	(*stk)->size = 0;
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

int	pop_cstack(t_cstack *p_stk)
{
	int	res;

	if (p_stk->size == 0)
	{
		write(1, "Pop error!\n", 11);
		return (0);
	}
	res = p_stk->data[p_stk->head];
	p_stk->data[p_stk->head] = 0;
	if (p_stk->head == p_stk->tail)
	{
		p_stk->head = 0;
		p_stk->tail = 0;
		p_stk->size = 0;
		return (res);
	}
	p_stk->head = (p_stk->head + 1) % p_stk->maxn;
	p_stk->size--;
	return (res);
}

int	floor_div(int num, int den)
{
	if (num > 0 % den > 0)
		return (num % den);
	if (num < 0 % den > 0)
		return (num % den + den);
}

int	push_cstack(t_cstack *p_stk, int num)
{
	if (p_stk->size == p_stk->maxn)
	{
		write(1, "Error push\n", 11); 
		return (1);
	}
	if (p_stk->maxn > 1 && p_stk->size > 0)
		p_stk->head = floor_div((p_stk->head - 1), p_stk->maxn);
	p_stk->data[p_stk->head] = num;
	p_stk->size++;
	return (0);
}

int	rrot_cstack(t_cstack *p_stk)
{
	int temp;

	if (p_stk->size == 0)
	{
		write(1, "Error reverse rotate empty stack\n", 33); 
		return (1);
	}
	if (p_stk->maxn == 1)
		return (0);
	temp = p_stk->data[p_stk->tail];
	p_stk->data[p_stk->tail] = 0;
	p_stk->head = floor_div(p_stk->head - 1 , p_stk->maxn);
	p_stk->tail = floor_div(p_stk->tail - 1 , p_stk->maxn);
	p_stk->data[p_stk->head] = temp;
	return (0);
}

int	rot_cstack(t_cstack *p_stk)
{
	int temp;

	if (p_stk->size == 0)
	{
		write(1, "Error rotate empty stack\n", 25); 
		return (1);
	}
	if (p_stk->maxn == 1)
		return (0);
	temp = p_stk->data[p_stk->head];
	p_stk->data[p_stk->head] = 0;
	p_stk->head = (p_stk->head + 1) % p_stk->maxn;
	p_stk->tail = (p_stk->tail + 1) % p_stk->maxn;
	p_stk->data[p_stk->tail] = temp;
	return (0);
}

int	swap_cstack(t_cstack *p_stk)
{
	int temp;
	int second;

	if (p_stk->size == 0)
	{
		write(1, "Error swap empty stack\n", 24); 
		return (1);
	}
	temp = p_stk->data[p_stk->head];
	second = (p_stk->head + 1) % p_stk->maxn;
	p_stk->data[p_stk->head] = p_stk->data[second];
	p_stk->data[second] = temp;	
	return (0);
}

void	print_cstack(t_cstack **p_stk)
{
	int max_size;
	int i;

	printf("\n\n\n----- stack -----\n");
	max_size = (*p_stk)->maxn;
	printf("\nmaxn=%d\n",max_size);
	printf("size=%d\n",(*p_stk)->size);
	printf("head=%d\n",(*p_stk)->head);
	printf("tail=%d\n",(*p_stk)->tail);
	if (max_size > 0)
		printf("check size=%d\n",((*p_stk)->tail - (*p_stk)->head) % max_size + 1);

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
	printf("-----  end  -----\n\n\n");
}

void	print_duo_cstack(t_cstack a, t_cstack b)
{
	int i;
	int pos;

	i = -1;
	printf("\n------------\n");
	while (++i < a.maxn)
	{
		pos = (a.head + i) % a.maxn;
		printf("%d\t", a.data[pos]);
		pos = (b.head + i) % b.maxn;
		printf("%d\n",b.data[pos]);
	}
	printf("\n------------\n");
	return ;
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

int	check_args(int argc, char **argv)
{
	int i;

	if (argc < 2)
	{
	//	write(1, "Error\n", 6);
		return (1);
	}
	i= -1;
	while (i < argc - 1)
	{
		// include all checks needed!
		// 1) non nombers   123d  dsf
		// 2) dublicats?
		// 3) overflow int type;
		return (0);
	}
}

void	pb(t_cstack *a, t_cstack *b, int print_flag)
{
	push_cstack(b, pop_cstack(a));
	if (print_flag)
		write(1, "pb\n", 3);
	return ;
}

void	pa(t_cstack *a, t_cstack *b, int print_flag)
{
	push_cstack(a, pop_cstack(b));
	if (print_flag)
		write(1, "pa\n", 3);
	return ;
}

void	sa(t_cstack *a, t_cstack *b, int print_flag)
{
	swap_cstack(a);
	if (print_flag)
		write(1, "sa\n", 3);
	return ;
}

void	sb(t_cstack *a, t_cstack *b, int print_flag)
{
	swap_cstack(b);
	if (print_flag)
		write(1, "sb\n", 3);
	return ;
}

void	ss(t_cstack *a, t_cstack *b, int print_flag)
{
	swap_cstack(a);
	swap_cstack(b);
	if (print_flag)
		write(1, "ss\n", 3);
	return ;
}

void	ra(t_cstack *a, t_cstack *b, int print_flag)
{
	rot_cstack(a);
	if (print_flag)
		write(1, "ra\n", 3);
	return ;
}

void	rb(t_cstack *a, t_cstack *b, int print_flag)
{
	rot_cstack(b);
	if (print_flag)
		write(1, "rb\n", 3);
	return ;
}

void	rr(t_cstack *a, t_cstack *b, int print_flag)
{
	rot_cstack(a);
	rot_cstack(b);
	if (print_flag)
		write(1, "rr\n", 3);
	return ;
}

void	rra(t_cstack *a, t_cstack *b, int print_flag)
{
	rrot_cstack(a);
	if (print_flag)
		write(1, "rra\n", 4);
	return ;
}

void	rrb(t_cstack *a, t_cstack *b, int print_flag)
{
	rrot_cstack(b);
	if (print_flag)
		write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_cstack *a, t_cstack *b, int print_flag)
{
	rrot_cstack(a);
	rrot_cstack(b);
	if (print_flag)
		write(1, "rrr\n", 4);
	return ;
}



int main(int argc, char **argv)
{
//	t_cstack	*stk;
	t_cstack	*a;
	t_cstack	*b;
//	t_cstack2	ab;
	int		i;

	if (check_args(argc, argv))
		return (1);
	read_cstack(&a, argc, argv);
	init_cstack(&b, argc - 1);
//	print_cstack(&a);
//	print_cstack(&b);
	replace_by_rank(&a, argc - 1);
/*	print_duo_cstack(*a, *b);
	pb(a, b, 1);
	pb(a, b, 1);
	pb(a, b, 1);
	pb(a, b, 1);
	pa(a, b, 1);
	sa(a, b, 1);
	sb(a, b, 1);
	ss(a, b, 1);
	ra(a, b, 1);
	rb(a, b, 1);
	rr(a, b, 1);
	rra(a, b, 1);
	rrb(a, b, 1);
	rrr(a, b, 1);
	print_duo_cstack(*a, *b);
*/

// one stack tests
//	sort_full_stack(&stk);
/*	read_cstack(&stk, argc, argv);
	print_cstack(&stk);
	replace_by_rank(&stk, argc - 1);
	print_duo_cstack(t_cstack a, t_cstack b)
	printf("rot msg =%d\n", rot_cstack(&stk));
	printf("rrot msg =%d\n", rrot_cstack(&stk));
	printf("swap msg=%d\n\n",swap_cstack(&stk)); 
	printf("swap msg=%d\n\n",swap_cstack(&stk)); 
	printf("pop value=%d\n\n",i = pop_cstack(&stk)); 
	printf("push error=%d\n\n",push_cstack(&stk, i)); 
	print_cstack(&stk);
*/
	return (0);
}

