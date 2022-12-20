# COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[31m
GREEN       = \033[32m 
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[36m
WHITE       = \033[1;37m

INFO = $(CYAN) ℹ️
SUCCESS = $(GREEN)✅
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)
TRASH = $(RED) 🗑


NAME = philo

SRC_DIR	=	./src/
OBJ_DIR	=	./obj/

SRCS = main.c parser.c init.c clear.c status.c routine.c utils.c parser_utils.c\

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC	= gcc
CFLAGS	=	-Wall -Wextra -Werror  -MD -g3


all: obj $(NAME) 

obj:
	@echo "$(INFO) Creating objects folder... $(NOC)"
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I ./includes/ -o $@ -c $<
-include $(OBJ_DIR)*.d

$(NAME): $(OBJS)
	@echo "$(INFO) Building $(NAME)...$(NOC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 
	@echo "$(SUCCESS)$(NAME) built successfully!$(NOC)"


clean:
	@echo "$(TRASH) Deleting .o files...$(NOC)"
	@rm -rf obj $(OBJS) 
	@echo "$(SUCCESS).o files deleted successfully!$(NOC)"
fclean: clean
	@echo "$(TRASH) Deleting $(NAME)...$(NOC)"
	@rm -rf obj $(NAME) 
	@echo "$(SUCCESS)$(NAME) deleted successfully!$(NOC)"

re: fclean all

.PHONY:     all clean fclean re