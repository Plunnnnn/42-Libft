CC = cc

CFLAGS = -Wall -Wextra -Werror -I include -I libft

SRCS = srcs/convert.c \
       srcs/ft_printf.c \
       srcs/h_flags.c \
       srcs/h_numbers.c \
       srcs/h_string.c \
       srcs/h_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = ft_printf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

$(LIBFT):
	$(MAKE) -C libft

.PHONY: all clean fclean re