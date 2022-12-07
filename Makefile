# COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

# SYMBOLS
INFO = $(CYAN)ℹ️ 
SUCCESS = $(GREEN)✅
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)


NAME = philo

SRC_DIR	=	./src/
OBJ_DIR	=	./obj/

SRCS = main.c parser.c parser_utils.c\

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC	= gcc
CFLAGS	=	-Wall -Wextra -Werror  -g3


all: obj $(NAME) 

obj:
	@echo "$(INFO)Creating objects folder... $(NOC)"
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I ./includes/ -o $@ -c $<

$(NAME): $(OBJS)
	@echo "$(INFO)Building $(NAME)...$(NOC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 
	@echo "$(SUCCESS)$(NAME) built successfully!$(NOC)"


clean:
	@echo "$(RED)Deleting .o files...$(NOC)"
	@rm -rf obj $(OBJS) 
	@echo "$(GREEN).o files deleted successfully!$(NOC)"
fclean: clean
	@echo "$(RED)Deleting $(NAME)...$(NOC)"
	@rm -rf obj $(NAME) 
	@echo "$(GREEN)$(NAME) deleted successfully!$(NOC)"

re: fclean all

.PHONY:     all clean fclean re