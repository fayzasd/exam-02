NAME		= libftprintf.a

SRCS		= ft_printf.c \

OBJS		= $(SRCS:%.c=%.o)
FLAGS		= -Wall -Werror -Wextra

$(NAME):
		gcc $(FLAGS) -c $(SRCS) 
		ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all
