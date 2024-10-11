CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I include

SRC_DIR = srcs
OBJ_DIR = obj

H_FILES = include/push_swap.h

SRC_FILES = $(SRC_DIR)/compress.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/binary_tools.c \
			$(SRC_DIR)/args.c \
			$(SRC_DIR)/actions.c \
			$(SRC_DIR)/integrity.c \
			$(SRC_DIR)/sort.c


OBJ_FILES = $(OBJ_DIR)/compress.o \
			$(OBJ_DIR)/utils.o \
			$(OBJ_DIR)/binary_tools.o \
			$(OBJ_DIR)/args.o \
			$(OBJ_DIR)/actions.o \
			$(OBJ_DIR)/integrity.o \
			$(OBJ_DIR)/sort.o

NAME = push_swap


all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC_FILES) $(H_FILES)

update:
	git add .
	git commit
	git push

re: fclean all

.PHONY: all clean fclean re

