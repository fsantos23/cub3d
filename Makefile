NAME_PROJECT = testeRay
OBJ_DIR = obj

# Use wildcard para pegar todos os arquivos .c dentro da pasta src e suas subpastas
SRCS = $(wildcard srcs/**/*.c)

# Transforma todos os arquivos .c em .o, colocando-os na pasta obj
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