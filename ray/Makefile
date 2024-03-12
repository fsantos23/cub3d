NAME_PROJECT = raycasting

SRCS = srcs/main.c srcs/functions.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -Iinc/
MLXFLAGS = -lXext -lX11 -lm -lz
LIBFT = libft/libft.a
MLX = minilibx_linux/libmlx_Linux.a

all: $(NAME_PROJECT)

.PHONY: all clean fclean re

$(NAME_PROJECT): $(OBJS)
	@make -s -C minilibx_linux/
	@make -s -C libft/
	@cc $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME_PROJECT) 
	@echo  "$(CYAN)Build ($(NAME_PROJECT)): $(GREEN)[Success]$(RESET)"

%.o: %.c
	@cc -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME_PROJECT) 
	@echo  "$(YELLOW)Cleaned $(CYAN)$(NAME_PROJECT): $(RED)[Success]$(RESET)"

re: fclean all

GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RED	= \033[1;31m
RESET = \033[0m