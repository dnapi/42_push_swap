NAME = push_swap

SRC =	push_swap.c \
	check_args.c \
	libft_mod.c \
	make_stack.c \
	direct_sorting.c \
	stack_push_swap.c \
	stack_rotate.c \
	oper_rx.c \
	oper_px_sx.c \
	oper_rrx.c

FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o  $(NAME)

debug: $(OBJ)
	cc $(FLAGS) $(OBJ) -o  $(NAME) -g

%.o: %.c
	cc $(FLAGS) -c $^ -o $@ -g 

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
