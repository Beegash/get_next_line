SRC = ft_source.c \
		ft_printf.c

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

NAME = libftprintf.a

all = $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: flean all

.PHONY : all clean fclean re