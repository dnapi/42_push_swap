#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
//# include <limits.h>

typedef struct	s_cstack
{
	int	*data;
	int	head;
	int	tail;
	int	maxn;
	int size;
}	t_cstack;

// ???  do you use it ?
typedef struct	s_circ_duo
{
	t_cstack a;
	t_cstack b;
}	t_circ_duo;

void	selection_sort(int arr[], int n); 

/// ###     LIBFT        #####

// this is modied version of ft_atoi in libft, int -> long
long long	ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);

/// ###    end of  LIBFT        #####


// make_stack.c
int	read_cstack(t_cstack *stk, int argc, char **argv);
int	init_cstack(t_cstack *stk, int size);
void	make_stack(t_circ_duo *stk, int arg, char **argv);

// direct_sorting.c
int	sort_full_stack(t_cstack *stk);
void	swap(int *a, int *b);
void	selection_sort(int arr[], int n);
int	replace_by_rank(t_cstack *p_stk, int size);

// stack_push_swap.c
int	floor_div(int num, int den);
int	pop_cstack(t_cstack *p_stk);
int	push_cstack(t_cstack *p_stk, int num);
int	swap_cstack(t_cstack *p_stk);

// stack_rotate.c
int	rrot_cstack(t_cstack *p_stk);
int	rot_cstack(t_cstack *p_stk);

// oper_px_sx.c
void	pb(t_circ_duo *stk, int print_flag);
void	pa(t_circ_duo *stk, int print_flag);
void	sa(t_circ_duo *stk, int print_flag);
void	sb(t_circ_duo *stk, int print_flag);
void	ss(t_circ_duo *stk, int print_flag);

// oper_rx.c
void	ra(t_circ_duo *stk, int print_flag);
void	rb(t_circ_duo *stk, int print_flag);
void	rr(t_circ_duo *stk, int print_flag);

// oper_rrx.c
void	rra(t_circ_duo *stk, int print_flag);
void	rrb(t_circ_duo *stk, int print_flag);
void	rrr(t_circ_duo *stk, int print_flag);


// check_args.c
void	print_cstack(t_cstack *p_stk);
//void	print_duo_cstack(t_cstack a, t_cstack b);
void	print_duo_cstack(t_circ_duo stk);
int	error_w(int condition);
int	check_args(int argc, char **argv);

#endif
