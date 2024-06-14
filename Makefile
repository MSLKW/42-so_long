NAME := so_long

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS_DIR := ./mandatory/
SRCS_FILES := so_long.c graphics.c map.c map_validator.c map_validator2.c map_utils.c
DEPS_FILES := so_long.h

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
DEPS = $(addprefix $(SRCS_DIR), $(DEPS_FILES))
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

# MAC:
$(NAME): $(OBJS) $(DEPS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C ./libft clean

# LINUX:
# LIBMLX = minilibx-linux/libmlx_Linux.a
# $(NAME): $(OBJS) $(DEPS) $(LIBFT) $(LIBMLX) 
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) -lX11 -lXext -o $(NAME)
# $(LIBMLX):
# 	make -C ./minilibx-linux

# clean:
# 	rm -f $(OBJS) $(BONUS_OBJS)
# 	make -C ./libft clean
# 	make -C ./minilibx-linux clean

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY = all clean fclean re

all: $(NAME) clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

bonus: $(BONUS_OBJS) $(DEPS)
	ar -rc $(NAME) $(BONUS_OBJS)