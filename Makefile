NAME = philo

SRC_DIR	=	./src/
OBJ_DIR	=	./obj/

SRCS = main.c parser.c parser_utils.c\

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC	= gcc
CFLAGS	=	-Wall -Wextra -Werror -pthread -g3


all: obj $(NAME) 

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) -I ./includes/ -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
	rm -rf obj $(OBJS) 

fclean: clean
	rm -rf obj $(NAME) 

re: fclean all

.PHONY:     all clean fclean re