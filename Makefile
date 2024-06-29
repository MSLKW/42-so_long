NAME := so_long

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS_DIR := ./mandatory/
SRCS_FILES := so_long.c graphics.c map.c map_validator.c map_validator2.c map_validator3.c map_utils.c movement_manager.c free_data.c
DEPS_FILES := so_long.h

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
DEPS = $(addprefix $(SRCS_DIR), $(DEPS_FILES))
OBJS = $(SRCS:.c=.o)

BONUS_SRCS_DIR := ./bonus/
BONUS_SRCS_FILES := so_long_bonus.c graphics_bonus.c map_bonus.c map_validator_bonus.c map_validator2_bonus.c map_validator3_bonus.c map_utils_bonus.c movement_manager_bonus.c free_data_bonus.c
BONUS_DEPS_FILES := so_long_bonus.h

BONUS_SRCS = $(addprefix $(BONUS_SRCS_DIR), $(BONUS_SRCS_FILES))
BONUS_DEPS = $(addprefix $(BONUS_SRCS_DIR), $(BONUS_DEPS_FILES))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = libft/libft.a

ifeq ($(shell uname), Darwin)
# MAC:
$(NAME): $(OBJS) $(DEPS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

bonus: $(BONUS_OBJS) $(BONUS_DEPS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C ./libft clean

else
# LINUX:
LIBMLX = minilibx-linux/libmlx_Linux.a
EFLAGS := -lX11 -lXext
$(NAME): $(OBJS) $(DEPS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) $(EFLAGS) -o $(NAME)
$(LIBMLX):
	make -C ./minilibx-linux

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C ./libft clean
	make -C ./minilibx-linux clean

endif

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
