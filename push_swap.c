/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apmikov <apmikov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:42:11 by apmikov           #+#    #+#             */
/*   Updated: 2023/12/28 04:42:14 by apmikov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	take_el(t_cstack stk, int i);
void	move_to_a(t_circ_duo *stk, int value);
void	move_to_a_imp(t_circ_duo *stk, int value);


int	is_ordered_list(int *x, int size)
{
	int	i;

	i = 0;
	while (x[i] < x[i + 1] && i < size - 1)
		i++;
	if (i == size - 1)
		return (1);
	return (0);
}

int	is_ordered_three(int x1, int x2, int x3)
{
	if (x1 < x2 && x2 < x3)
		return (1);
	return (0);
}



void	sort_two(t_circ_duo *stk)
{
	int	x0;
	int	x1;

	x0 = stk->a.data[stk->a.head];
	x1 = stk->a.data[(stk->a.head + 1) % stk->a.maxn];
	if (x0 > x1)
		sa(stk, 1);
	return ;
}

void	sort_three(t_circ_duo *stk)
{
	int	x[3];

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

void	move_quart2b(t_circ_duo *stk, int k, int i)
{
	int	num;
	int	count;

	num = (stk->a.maxn - 3) / k;
	//if (k == 1)
	//  num = stk->a.size - 3;
	count = 0;
	while (count < num && stk->a.size > 3)
	{
		//printf("num= %d, count=%d, flag=%d, i=%d, k=%d\n", num, count, flag, i, k);
		if (is_ordered_three(0, take_el(stk->a, 0) - num * i, num + 1))
		{
			pb(stk, 1);
			count++;
/*      if (take_el(stk->b, 0) < take_el(stk->b, 1) && take_el(stk->a, 0) > take_el(stk->a, 1))
          ss(stk,1);
        if (take_el(stk->b, 0) < take_el(stk->b, 1))
        sb(stk, 1);
        */
		}
		else if (take_el(stk->b, 0) - i * num > num / 2)
			rr(stk, 1);
		else
			ra(stk, 1);
		if (take_el(stk->b, 0) < take_el(stk->b, 1) && take_el(stk->a, 0) > take_el(stk->a, 1))
			ss(stk, 1);
		if (take_el(stk->b, 0) < take_el(stk->b, 1))
			sb(stk, 1);
//   if (take_el(stk->a, 0) < take_el(stk->a, 1))
//    sa(stk,1);
	}
}

/* k = N / 20   -> 669 / 8180
  // k = N / 40   -> 925 / 6216 stable
  // 100  10-> 780   30->765 
  // 500  60->6720  50->6262
  // ss added
  // 30/100 -> 728    50/500 ->  5893    ss
  // 15/100 -> 656    30/500 ->  6370    ss
  // 15/100 -> 653     50/500 ->  5771   ss+sb
  //  added sa increase number of steps
  //  50/500 -> 5785 !!!   15/500 ~> 9000   30/500 -> 6300
  //  55/500 -> 5859    45 -> 5830 
*/
void	sort_medium(t_circ_duo *stk)
{
	int	i;
	int	k;

	if (stk->a.maxn < 250)
		k = stk->a.maxn / 15;
	else
		k = stk->a.maxn / 50;
	i = -1;
	while (++i < k)
		move_quart2b(stk, k, i);
	move_quart2b(stk, 1, 0);
	sort_three(stk);
  i = stk->a.maxn - 3;
	while (i > 0)
		move_to_a_imp(stk, i--);
//	while (stk->a.size < stk->a.maxn)
	//	move_to_a(stk, stk->a.maxn - stk->a.size);
	return ;
}

void	sort_small(t_circ_duo *stk)
{
	int	size;

	size = stk->a.size;
	while (stk->a.size > 3)
	{
		if (take_el(stk->a, 1) < take_el(stk->a, 0) && take_el(stk->a, 0) < size - 2)
			sa(stk, 1);
		if (take_el(stk->a, 0) < size - 2)
			pb(stk, 1);
		else 
			ra(stk, 1);
	}
	sort_three(stk);
	while (stk->a.size < stk->a.maxn)
		move_to_a(stk, stk->a.maxn - stk->a.size);
	return ;
}

int	take_el(t_cstack stk, int i)
{
	int	pos;

	pos = (stk.head + i + stk.maxn) % stk.maxn;
	return (stk.data[pos]);
}

int	*take_all(t_cstack stk, int *dat)
{
	int	pos;
	int	i;

	i = -1;
	pos = stk.head % stk.maxn;
	while (++i < stk.size)
		dat[i] = stk.data[(i + pos) % stk.maxn];
	return (dat);
}

void	repeat_f(void (*f)(t_circ_duo *, int), int n, t_circ_duo *stk, int i)
{
	while (n-- > 0)
		f(stk, i);
}

void	move_to_a(t_circ_duo *stk, int value)
{
	int	i;
	int	size;

	i = -1;
	size = stk->b.size;
	while (++i < size)
		if (take_el(stk->b, i) == value)
			break ;
	if (i == size)
		return ;
	if (i > size / 2)
		repeat_f(rrb, size - i, stk, 1);
	else if (i > 0)
		repeat_f(rb, i, stk, 1);
	pa(stk, 1);
	return ;
}


// do we use it?
int min_value(int x, int y)
{
  return ((x > y) * y + (x <= y) * x);
}

int position_in_stack(t_cstack a, int value)
{
  int i;

  i = 0;
  while (i < a.size && value != take_el(a, i))
    i++;
  return (i);
}

void  do_magic_r(t_circ_duo *stk, int value, int flag)
{
  int i;
  while (value != take_el(stk->b, 0))
  {
    if (take_el(stk->a, 0) > take_el(stk->b, 0) && 
      (take_el(stk->a, -1) == stk->a.maxn || take_el(stk->a, -1) < take_el(stk->b, 0)))
      pa(stk, flag);
    else
    {
      i = position_in_stack(stk->b, value);
      if (i > stk->b.size / 2)
        rrb(stk, flag);
      else if (i > 0)
        rb(stk, flag);
    }
  }
  i = 0;
  while (take_el(stk->a, 0) != value + 1)
  {
//    print_duo_cstack(*stk);
//    printf("value=%d\n", value);
    ra(stk, flag);
  }
}

void	move_to_a_imp(t_circ_duo *stk, int value)
{
	int	i;

	i = -1;
  print_duo_cstack(*stk);
  printf("value=%d\n", value);
	while (++i < stk->b.size)
		if (take_el(stk->b, i) == value)
			break ;
	if (i == stk->b.size)
  {
    rra(stk, 1);
  //  printf("i am crazy loop\n");
    return ;
  }
  do_magic_r(stk, value, 1);
	pa(stk, 1);
	return ;
}

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

int	main(int argc, char **argv)
{
	t_circ_duo	stk;

	if (check_args(argc, argv))
		return (1);
	if (make_stack(&stk, argc, argv))
		return (error_w(1));
	replace_by_rank(&stk.a, argc - 1);
//  print_duo_cstack(stk);
//  printf("position=%d\n", position_in_stack(stk.a, 4));
	sort_circ(&stk, argc - 1);
  print_duo_cstack(stk);
//	print_cstack(&stk.a);
	free(stk.a.data);
	free(stk.b.data);
	return (0);
}
