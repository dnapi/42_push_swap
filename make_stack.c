#include "push_swap.h"

void make_stack(t_circ_duo *stk, int argc, char **argv)
{
  t_cstack  a;
  t_cstack  b;

  read_cstack(&a, argc, argv);
  init_cstack(&b, argc - 1);
  stk->a = a;
  stk->b = b;
  return ;
}

int	read_cstack(t_cstack *stk, int argc, char **argv)
{
	int *dat;
	int	i;

	if (!stk || argc == 1)
		return (1);
	dat = (int *)malloc((argc - 1) * sizeof(int));
	if (!dat)
		return (1);
	i = -1;
	while (++i < argc - 1)
		dat[i] = ft_atoi(argv[i + 1]);
	stk->data = dat;
	stk->maxn = argc - 1;
	stk->head = 0;
	stk->tail = argc - 2;
	stk->size = argc - 1;
	return (0);
}

int	init_cstack(t_cstack *stk, int size)
{
	int *dat;
	int	i;

	if (!stk || size < 1)
		return (1);
	dat = (int *)malloc(size * sizeof(int));
	if (!dat)
		return (1);
	i = -1;
	while (i < size)
		dat[i++] = 0;
	stk->data = dat;
	stk->maxn = size;
	stk->size = 0;
	stk->head = 0;
	stk->tail = 0;
	stk->size = 0;
	return (0);
}
