NAME = libftprintf.a

SRC = ft_printbase.c ft_printf.c ft_printstr.c ft_printchar.c
LIBFT_DIR = libft

FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $@
	ar -ruvcs $(NAME) $(OBJ)

%.o: %.c
	cc $(FLAGS) -c $^ -o $@ 

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f ${OBJ}

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
