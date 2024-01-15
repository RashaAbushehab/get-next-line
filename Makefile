NAME = get_next_line.a

file = get_next_line.c \
		get_next_line_utils.c

OBJ = $(files:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: NAME

$(NAME) = $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all