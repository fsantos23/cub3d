SRCS_DIR = srcs

SRCS		=	$(SRCS_DIR)/main.c \
				$(SRCS_DIR)/flood_fill.c \
				$(SRCS_DIR)/free.c \
				$(SRCS_DIR)/list.c \
				$(SRCS_DIR)/parse.c \
				$(SRCS_DIR)/utils.c \
				$(SRCS_DIR)/start.c \
				

OBJS		=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	=	objs

NAME		=	cub3d

CC			=	gcc

LIBFT		=	libft/libft.a

CFLAGS		=	 -Wall -Wextra -Werror -g #-fsanitize=address

RM			=	rm -rf

MLX 		=	mlx_linux/libmlx.a

MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11 

MLX_DIR		= 	mlx_linux

INC			=	-Iincludes -I/usr/include -Ilibft/includes -Iget_next_line/includes -Imlx_linux

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"



all:		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS)
			@echo $(RED) "[🚀Compiling libft...🚀]" $(EOC)
			@make -C libft > /dev/null
			@echo $(GREEN) "[Libft compiled!]" $(EOC)
			$(CC) $(OBJS) $(LIBFT) $(GNL) $(CFLAGS) $(MLXFLAGS) $(CFLAGS) $(INC) -o $(NAME)
			@echo $(GREEN) "[Minishell compiled!]" $(EOC)

clean:
			@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
			$(RM) $(OBJS)

fclean:		clean
			@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
			$(RM) $(NAME)
			$(RM) *.out
			$(RM) $(OBJS_DIR)
			@make fclean -C libft > /dev/null
			@echo $(GREEN) "[All cleaned!]" $(EOC)

re:			fclean all

r:
	make re  > /dev/null && clear && ./$(NAME)

cl: 
	clear && make r

valgrind:
	make re  > /dev/null && valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY:		all clean fclean re