NAME_PROJECT = cub3d

SRCS = srcs/main/main.c srcs/ray/functions.c srcs/ray/player.c srcs/ray/3d.c \
		srcs/ray/utils.c srcs/parser/aux/aux.c srcs/parser/aux/aux2.c srcs/parser/aux/free.c \
		srcs/parser/init.c srcs/parser/parse_aux_functions.c srcs/parser/parse_map.c \
		srcs/parser/parse_texture_colors.c srcs/parser/parser.c srcs/parser/save_data.c \
		srcs/ray/exit.c

OBJS = $(SRCS:.c=.o)

FLAGS = #-Wall -Wextra -Werror -g -O3

MLXFLAGS = -L ./minilibx/ -lmlx -Ilmlx -lXext -lX11 -lm

LIBFT = libft/libft.a

MLX = minilibx/libmlx_Linux.a

INC = -Iincludes -I/usr/include -Ilibft/includes -Iget_next_line/includes -Iminilibx

all: $(NAME_PROJECT)

$(NAME_PROJECT): $(OBJS)
	@echo $(RED) "[🚀Compiling MLX...🚀]" $(EOC)
	@make -s -C minilibx/ > /dev/null
	@echo $(GREEN) "[MLX Compiled!]" $(EOC)
	@echo $(RED) "[🚀Compiling libft...🚀]" $(EOC)
	@make -s -C libft/
	@echo $(GREEN) "[Libft Compiled!]" $(EOC)
	@cc $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) $(INC) -o $(NAME_PROJECT) 
	@echo  $(GREEN) "[Cub3d Compiled!]" $(EOC)

%.o: %.c
	@cc $(INC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make clean -s -C minilibx/
	@make fclean -s -C libft/

fclean: clean
	@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
	@rm -f $(NAME_PROJECT)

re: fclean all

BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

.PHONY: all clean fclean re