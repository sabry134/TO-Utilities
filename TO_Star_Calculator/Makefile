SRC		=	main.c	\

OBJ     =	$(SRC:.c=.o)

NAME    =	challenge_calculator

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)
	echo -e "\e[92;5m       ====Confirmation Allowed====      \e[0m"

clean:
	rm -f $(OBJ)
	rm -f *gcno

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f *.o

re:     fclean all