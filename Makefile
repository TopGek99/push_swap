NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
INC = -Iincludes/ -I$(LIB_DIR)/includes/

SRCS = push_swap.c stack_methods.c operations.c

OBJS = $(SRCS:.c=.o)
PUSH_OBJ = $(addprefix $(OBJ_DIR),$(OBJS))

LIB_DIR = libft/
SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(NAME)

$(NAME): $(PUSH_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(NAME) $(PUSH_OBJ) -L $(LIB_DIR) -lft
	@echo "##### push_swap compiling finished! #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(CFLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(PUSH_OBJ)
	@echo "##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(PUSH_NAME)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re