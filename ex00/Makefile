NAME	=	bureaucrat

CC	=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC	=	main.cpp \
		Bureaucrat.cpp

HEADER	=	Bureaucrat.hpp

OBJ_DIR	=	objs
OBJ	=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:	$(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f leaks.txt

fclean:	clean
	rm -f $(NAME)

re: fclean all

test:	re
	valgrind --leak-check=full --log-file="leaks.txt" ./$(NAME)
