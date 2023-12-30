#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "push_swap.h"

//valgrind --tool=memcheck <your_app> <your_apps_params>

void    free_stack_duo(t_circ_duo *stk)
{
    if (stk->a.data)
        free(stk->a.data);
    stk->a.data = NULL;
    if (stk->b.data)
        free(stk->b.data);
    stk->b.data = NULL;
}

int free_arg_v(char **argv, char **arg_v, int arg_c)
{
    if (arg_v != argv)
        clean_array(&arg_v, arg_c + 1);
    return (1);
}

int main(int argc, char **argv)
{
    t_circ_duo  stk;
    char        **arg_v;
    int         arg_c;
    char        *str;

    //remove printf !
    //remove stdio in header
    if (argc == 1)
        return (0);
    arg_v = argv;
    arg_c = argc;
    if (argc == 2 && ft_strchr(argv[1], (int)' '))
    {
        str = ft_strjoin_mod(argv[0], argv[1], ' ');
        arg_v = ft_split(str, ' ');
        arg_c = (int)word_count_char(argv[1], ' ') + 1;
        free(str);
    }
    if (check_args(arg_c, arg_v))
        return (free_arg_v(argv, arg_v, arg_c));
    if (make_stack(&stk, arg_c, arg_v))
        return (error_w(free_arg_v(argv, arg_v, arg_c)));
	print_duo_cstack(stk);
    free_arg_v(argv, arg_v, arg_c);
    free_stack_duo(&stk);
	
	char *pnt;
	int fd = 0;
	pnt = get_next_line(0);
	while (pnt)
	{
		printf("%s",pnt);
		pnt = get_next_line(fd);
	}
	printf("%s",pnt);
	close(fd);
	return (0);
}
