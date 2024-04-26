NAME_PROJECT = cub3D
OBJ_DIR = obj

SRCS = srcs/parser/parser.c srcs/parser/init.c srcs/parser/parse_map.c srcs/parser/save_data.c \
	srcs/parser/parse_aux_functions.c srcs/parser/parse_texture_colors.c srcs/aux/free.c \
	srcs/aux/aux.c srcs/aux/aux2.c srcs/aux/aux4.c srcs/aux/aux3.c srcs/hooks/hook.c \
	srcs/hooks/move_formulas.c srcs/raycast/raycast_formulas.c srcs/raycast/raycast.c \
	srcs/textures/textures.c srcs/main/main.c

OBJS = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

FLAGS = -g -Wall -Wextra -Werror -Iinc/
MLXFLAGS = -lXext -lX11 -lm -lz
LIBFT = libft/libft.a
MLX = minilibx/libmlx_Linux.a

all: $(NAME_PROJECT)

.PHONY: all clean fclean re

$(NAME_PROJECT): $(OBJS)
	@make -s -C minilibx/
	@make -s -C libft/
	@cc $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME_PROJECT) 
	@echo  "$(CYAN)Build ($(NAME_PROJECT)): $(GREEN)[Success]$(RESET)"

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	@cc -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -s -C minilibx/
	@make fclean -s -C libft/

fclean: clean
	@rm -f $(NAME_PROJECT) 
	@echo  "$(YELLOW)Cleaned $(CYAN)$(NAME_PROJECT): $(RED)[Success]$(RESET)"

re: fclean all

GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RED	= \033[1;31