NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC_FILES = ft_bzero.c ft_memcpy.c ft_memset.c ft_strlen.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_strdup.c \
		ft_strtrim.c ft_strlcpy.c ft_strnstr.c ft_strchr.c ft_substr.c ft_strrchr.c ft_split.c ft_calloc.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strjoin.c ft_strlcat.c \
		ft_strncmp.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		ft_printf/ft_printf.c  ft_printf/ft_print_string.c  ft_printf/ft_puthex.c  ft_printf/ft_putptr.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS_DIR = src

SRCS = $(addprefix $(SRCS_DIR)/,$(SRC_FILES))

OBJ_DIR = obj

RM = rm -f 

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	ar -csr $@ $^

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(shell dirname $@)
	cc $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all