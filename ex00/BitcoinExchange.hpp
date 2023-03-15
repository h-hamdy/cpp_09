#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <list>
# include <vector>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cstring>

typedef struct btc_amount {
	std::string date;
	std::string value;
} amount;
// class Bitcoin {
// private:	
// 	struct bitcoin_amount {
// 		std::string date;
// 		std::string value;
// 	};
// 	bitcoin_amount btc_amount;
// public:
// 	Bitcoin ();
// 	Bitcoin (std::string _date, std::string _value);
// 	Bitcoin (const Bitcoin &obj);
// 	~Bitcoin ();

// };

#endif