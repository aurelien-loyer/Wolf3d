##
## EPITECH PROJECT, 2024
## makefile
## File description:
## make file
##

NAME	=	wolf3d

RM =    rm -rf

CFLAGS	=	-Wall -Werror -Wextra -I ./include

SRC =	$(wildcard utils/*.c src/*.c src/**/*.c)

OBJ	=	$(SRC:.c=.o)

VFLAG = --leak-check=full --show-leak-kinds=all --track-origins=yes

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all:	$(OBJ)
	gcc $(OBJ) $(CFLAGS) -o $(NAME) $(CSFML)

debug:
	gcc $(SRC) $(CFLAGS) -g3 -ggdb -o $(NAME) $(CSFML)

clean:
	$(RM) $(OBJ)
	$(RM) **/*#
	$(RM) **/*~
	$(RM) *#
	$(RM) *~

fclean:
	make clean
	$(RM) $(NAME)

re:	fclean all

valgrind:	all
	gcc $(SRC) $(CFLAGS) -g3 -ggdb -o $(NAME) $(CSFML)
	valgrind $(VFLAG) ./$(NAME)

valgrind_with_arg: all
	gcc $(SRC) $(CFLAGS) -g3 -ggdb -o $(NAME) $(CSFML)
	valgrind $(VFLAG) ./$(NAME) \
	$(shell read -p "Test for valgrind: " data; echo $$data)

cs:	fclean
	coding-style .
	cat coding-style-reports.log
	$(RM) coding-style-reports.log

git:	fclean
	git add $(shell read -p "Enter files to add: " data; echo $$data)
	git commit -m \
	"$(shell read -p 'Enter commit message: ' message; echo $$message)"
	git push
