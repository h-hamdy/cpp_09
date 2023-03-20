#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <list>
# include <map>
# include <vector>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <exception>
#include <string.h>

typedef struct btc_amount {
	std::string 	date;
	std::string 	value;
} amount;

typedef struct btc_price {
	std::string date;
	std::string price;
}	price;

std::string	check_value (std::string value);
bool 		check_range(char *token, int i);
bool 		is_valid_float(char* str);
bool		is_digite(char *str);
void		throw_errr(char *msg, char *str);

#endif