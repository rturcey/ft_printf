FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS_DIR = ./sources/

SRCS = $(SRCS_DIR)ft_applyflags.c $(SRCS_DIR)ft_lists.c $(SRCS_DIR)ft_printf_utils.c $(SRCS_DIR)ft_parse.c \
 $(SRCS_DIR)ft_applyflags_dash.c $(SRCS_DIR)ft_printf.c $(SRCS_DIR)ft_prints.c $(SRCS_DIR)ft_memutils.c\
 $(SRCS_DIR)ft_parseflags.c $(SRCS_DIR)ft_printf_utils2.c $(SRCS_DIR)ft_printf_utils3.c
INCLUDES_DIR = ./includes/

INCLUDES = $(INCLUDES_DIR)header.h
OPTIONS = -I $(INCLUDES)
OBJS = $(SRCS:.c=.o)

.c.o:		$(SRCS) $(INCLUDES)
			cc $(FLAGS) -I $(INCLUDES_DIR) -c $^ -o $(<:.c=.o)

$(NAME):	$(OBJS) $(INCLUDES)
			ar rcs $@ $^

all:		$(NAME)

clean :
			rm -f $(OBJS)

fclean :	clean
			rm -f $(NAME)

re :		fclean all
