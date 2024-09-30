CC = cc
CFLAGS = -Wall -Wextra -Werror -I include

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRC_DIR = srcs
OBJ_DIR = obj

H_FILES = include/libft.h \
		 include/ft_printf.h \

SRC_FILES = $(SRC_DIR)/convert.c \
			 $(SRC_DIR)/ft_printf.c \
			 $(SRC_DIR)/h_numbers.c \
			 $(SRC_DIR)/h_string.c \
			 $(SRC_DIR)/h_utils.c

OBJ_FILES = $(OBJ_DIR)/convert.o \
			$(OBJ_DIR)/ft_printf.o \
			$(OBJ_DIR)/h_numbers.o \
			$(OBJ_DIR)/h_string.o \
			$(OBJ_DIR)/h_utils.o

NAME = ft_printf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBFT_LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ_FILES)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT_LIB)

norme:
	rm -f $(OBJ_FILES) ${NAME}
	norminette $(SRC_FILES) $(H_FILES)

update:
	git add .
	git commit
	git push

re: fclean all
