#include "checker.h"
#include "push_swap.h"

void	init_oper(char p_str[][5])
{
	ft_strlcpy(p_str[PA], "pa\n", 4);
	ft_strlcpy(p_str[PB], "pb\n", 4);
	ft_strlcpy(p_str[SA], "sa\n", 4);
	ft_strlcpy(p_str[SB], "sb\n", 4);
	ft_strlcpy(p_str[SS], "ss\n", 4);
	ft_strlcpy(p_str[RA], "ra\n", 4);
	ft_strlcpy(p_str[RB], "rb\n", 4);
	ft_strlcpy(p_str[RR], "rr\n", 4);
	ft_strlcpy(p_str[RRA], "rra\n", 5);
	ft_strlcpy(p_str[RRB], "rrb\n", 5);
	ft_strlcpy(p_str[RRR], "rrr\n", 5);
}

void	init_oper_fun(t_oper_stk *fun)
{
	fun[PA] = pa;
	fun[PB] = pb;
	fun[SA] = sa;
	fun[SB] = sb;
	fun[SS] = ss;
	fun[RA] = ra;
	fun[RB] = rb;
	fun[RR] = rr;
	fun[RRA] = rra;
	fun[RRB] = rrb;
	fun[RRR] = rrr;
}

int	oper_id(char *str, t_circ_duo *p_stk)
{
	char p_str[11][5];
	t_oper_stk	fun[11];
	int	i;

	init_oper(p_str);
	init_oper_fun(fun);
	i = 0;
	while (i < 11)
	{
//		p_str[i][0] = '\0';
		if (!ft_strncmp(str, p_str[i], 4))
		{
			fun[i](p_stk, 0);
			break;
		}
		i++;
	}
//	printf("i=%i\n",i);
	return (i);
}

int	is_sorted_duo(t_circ_duo stk)
{
	int	i;

	if (stk.a.size != stk.a.maxn || stk.b.size != 0)
		return (0);
	i = -1;
	while (++i < stk.a.maxn)
	{
		if (take_el(stk.a, i) != i + 1)
			break ;			
	}
	if (i == stk.a.maxn)
		return (1);
	return (0);
}
