NAME := so_long

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS_DIR := ./
SRCS_FILES := so_long.c
DEPS_FILES := so_long.h

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
DEPS = $(addprefix $(SRCS_DIR), $(DEPS_FILES))
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
LIBMLX = minilibx-linux/libmlx_Linux.a
.PHONY = all clean fclean re

$(NAME): $(OBJS) $(DEPS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) -lX11 -lXext -o $(NAME)

$(LIBFT):
	make -C ./libft

$(LIBMLX):
	make -C ./minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME) clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C ./libft clean
	make -C ./minilibx-linux clean

re: fclean all

bonus: $(BONUS_OBJS) $(DEPS)
	ar -rc $(NAME) $(BONUS_OBJS)