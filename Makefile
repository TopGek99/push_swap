NAME=push_swap
CC=gcc
CFLAGS=-Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_DIR) -Ilibft/includes
LDFLAGS=-Llibft -lft 

SRC_DIR=src
INC_DIR=includes

_INC = push_swap.h
INC = $(patsubst %, $(INC_DIR)/%, $(_INC))

OBJ = push_swap.o operations.o list_methods.o

all: $(NAME)

%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)

re: fclean all