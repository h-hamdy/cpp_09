CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME	=	btc

SCR		=	main.cpp \
			BitcoinExchange.cpp

all:	$(NAME)

$(NAME):	$(SCR)
	$(CC) $(CFLAGS) $(SCR) -o $(NAME)

clean:
	rm -rf $(NAME)

re:	clean all