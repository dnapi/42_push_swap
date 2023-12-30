NAME = push_swap

BONUS = checker

SRC =	push_swap.c \
	check_args.c \
	libft_mod.c \
	make_stack.c \
	direct_sorting.c \
	stack_push_swap.c \
	stack_rotate.c \
	oper_rx.c \
	oper_px_sx.c \
	oper_rrx.c \
	sort.c \
	sort_fun.c \
	stack_elem.c \
	ft_split.c

SRC_BONUS = get_next_line.c \
			get_next_line_utils.c \
			checker.c \
	check_args.c \
	libft_mod.c \
	make_stack.c \
	direct_sorting.c \
	stack_push_swap.c \
	stack_rotate.c \
	oper_rx.c \
	oper_px_sx.c \
	oper_rrx.c \
	sort.c \
	sort_fun.c \
	stack_elem.c \
	ft_split.c

FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o  $(NAME)

debug: $(OBJ)
	cc $(FLAGS) $(OBJ) -o  $(NAME) -g

%.o: %.c
	cc $(FLAGS) -c $^ -o $@ -g 

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	cc $(FLAGS) $(OBJ_BONUS) -o $(BONUS)

clean:
	rm -f ${OBJ} ${OBJ_BONUS}

fclean: clean
	rm -f ${NAME} $(BONUS) 

re: fclean all

.PHONY: all clean fclean re
