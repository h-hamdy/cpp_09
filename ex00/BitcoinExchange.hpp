#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <list>
# include <vector>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <exception>

typedef struct btc_amount {
	std::string date;
	std::string value;
} amount;

typedef struct btc_price {
	std::string date;
	std::string price;
}	price;

#endif