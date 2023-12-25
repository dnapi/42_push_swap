#include "push_swap.h"


int take_el(t_cstack stk, int i);



int is_ordered_list(int *x, int size)
{
  int i;
  
  i = 0;
  while (x[i] < x[i + 1] && i < size - 1)
    i++;
  if (i == size - 1)
    return (1);
  return (0);
}

int is_ordered_three(int x1, int x2, int x3)
{
  if (x1 < x2 && x2 < x3)
    return (1);
  return (0);
}

// 123
// 132  sa ra
// 213 sa
// 231  rra
// 312  ra
// 321`sa rra
void  sort_three(t_circ_duo *stk)
{
  int x[3];

  x[0] = stk->a.data[stk->a.head];
  x[1] = stk->a.data[(stk->a.head + 1) % stk->a.maxn];
  x[2] = stk->a.data[(stk->a.head + 2) % stk->a.maxn];
  if (is_ordered_three(x[0], x[2], x[1]))
  {
    sa(stk, 1);
    ra(stk, 1);
  }
  else if (is_ordered_three(x[1], x[0], x[2]))
    sa(stk, 1);
  else if (is_ordered_three(x[2], x[0], x[1]))
    rra(stk, 1);
  else if (is_ordered_three(x[1], x[2], x[0]))
    ra(stk, 1);
  else if (is_ordered_three(x[2], x[1], x[0]))
  {
    sa(stk, 1);
    rra(stk, 1);
  }
  return ;
}

int take_el(t_cstack stk, int i)
{
  int pos;

  pos = (stk.head + i + stk.maxn) % stk.maxn;
  return (stk.data[pos]);
}

int *take_all(t_cstack stk, int *dat)
{
  int pos;
  int i;

  i = -1;
  pos = stk.head % stk.maxn;
  while (++i < stk.size)
    dat[i] = stk.data[(i + pos) % stk.maxn];
  return (dat);
}

void sort_circ(t_circ_duo *stk, int n)
{
  (void)stk;
  if (n == 3)
    sort_three(stk);
  return ;
}

int main(int argc, char **argv)
{
  t_circ_duo stk;
  //int dat[100];
 // int i;
  
	if (check_args(argc, argv))
  {
		return (1);
  }
  make_stack(&stk, argc, argv);
	replace_by_rank(&stk.a, argc - 1);
  print_duo_cstack(stk);
  sort_circ(&stk, argc - 1);
  print_duo_cstack(stk);
//	print_cstack(&stk.a);
//	print_cstack(&stk.b);
/*  pb(&stk, 1);
  pb(&stk, 1);
  pb(&stk, 1);
  print_duo_cstack(stk);
  printf("el 0 = %d\n",take_el(stk.a, 0));
  printf("el 3 = %d\n",take_el(stk.a, 3));
  printf("el 8 = %d\n",take_el(stk.a, 8));
  i = -1;
  take_all(stk.a, dat);
  while (++i < stk.a.size)
    printf("i=%d, el=%d\n", i, dat[i]);

  print_cstack(&stk.b);
  sort_three(&stk.b);
  sa(&stk, 1);
  sb(&stk, 1);
  print_duo_cstack(stk);
  ss(&stk, 1);
  print_duo_cstack(stk);
*/

	return (0);
}

