SRCS	= ${shell find ./srcs -type f -name "*\.c"}
OBJS	= $(SRCS:.c=.o)
INCLUDE	= -I ./my_libc/libft.h
INCLUDE	+= -I ./includes
NAME	= bfi
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
LIBC	= my_libc/libft.a

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./my_libc
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./my_libc
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
