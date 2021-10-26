CC=gcc
CFLAGS=-Wall -Wextra -Werror

NAME=libftprintf.a

SRCS = ft_printf.c output_1.c output_2.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY : all
all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)


.PHONY : clean
clean :
	rm -rf $(OBJS)

.PHONY : fclean
fclean : clean
	rm -fr $(NAME)

.PHONY : re
re : fclean all
