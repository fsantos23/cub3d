NAME_PROJECT = cub3d

SRCS = srcs/main/main.c srcs/ray/functions.c srcs/ray/player.c srcs/ray/3d.c \
		srcs/ray/utils.c srcs/parser/aux/aux.c srcs/parser/aux/aux2.c srcs/parser/aux/free.c \
		srcs/parser/init.c srcs/parser/parse_aux_functions.c srcs/parser/parse_map.c \
		srcs/parser/parse_texture_colors.c srcs/parser/parser.c srcs/parser/save_data.c

OBJS = $(SRCS:.c=.o)

FLAGS = -g #-Wall -Wextra -Werror

MLXFLAGS = -L ./minilibx/ -lmlx -Ilmlx -lXext -lX11

LIBFT = libft/libft.a

MLX = minilibx/libmlx_Linux.a

INC = -Iincludes -I/usr/include -Ilibft/includes -Iget_next_line/includes -Iminilibx -lm

all: $(NAME_PROJECT)

$(NAME_PROJECT): $(OBJS)
	@make -s -C minilibx/
	@make -s -C libft/
	@cc $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) $(INC) -o $(NAME_PROJECT) 
	@echo  "$(CYAN)Build ($(NAME_PROJECT)): $(GREEN)[Success]$(RESET)"

%.o: %.c
	@cc $(INC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make clean -s -C minilibx/
	@make fclean -s -C libft/

fclean: clean
	@rm -f $(NAME_PROJECT)
	@echo  "$(YELLOW)Cleaned $(CYAN)$(NAME_PROJECT): $(RED)[Success]$(RESET)"

re: fclean all

GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RED	= \033[1;31m
RESET = \033[0m

.PHONY: all clean fclean re