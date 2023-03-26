CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	PmergeMe

SCR		=	main.cpp \
			pmergeMe.cpp

all:	$(NAME)

$(NAME):	$(SCR)
	$(CC) $(CFLAGS) $(SCR) -o $(NAME)

clean:
	rm -rf $(NAME)

re:	clean all