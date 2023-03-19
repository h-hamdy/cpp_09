# include "BitcoinExchange.hpp"

int check_line (std::string date, amount my_amount, std::string value)
{
	char *str = strdup(date.c_str());
	int flag = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] == '-')
			flag++;
	if (flag != 2) {
		std::cerr << "Invalid date format." << std::endl;
		return (0);
	}
	int i = 0;
	char *token = std::strtok(str, "-");
	while (token != NULL) {
		i++;
		if (!is_digite(token)) {
			std::cerr << "Invalid date format." << std::endl;
			return (0);
		}
		if (!check_range(token, i)) {
			std::cerr << "Error: too large a number." << std::endl;
			return (0);
		}
		token = std::strtok(NULL, "-");
	}
	if (i != 3) {
		std::cerr << "Invalid date format." << std::endl;
		return (0);
	}
	std::string value_msg = check_value(value);
	if (value_msg != "") {
		std::cerr << value_msg << std::endl;
		return 0;
	}
	free (str);
	// my_amount.
	(void)my_amount;
	// btc_amount.push_back(btc);
	return (1);
}

int get_data(amount my_amount, std::string line)
{
	std::string date;
	std::string value;
	size_t pos = line.find("|");
	if (pos == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return 0;
	}
	date = line.substr(0, pos - 1);
	if (strlen(line.c_str()) > pos + 2)
		value = line.substr(pos + 2);
	else {
		std::cerr << "value doesn't exist." << std::endl;
		return 0;
	}
	if (!check_line(date, my_amount, value))
		return (0);
	return (1);
}

void	parse_btc_price (std::list<price> &btc_price)
{
	price my_price;
	std::string line;
	std::ifstream infile("data.csv");
	if (!infile.good())
		throw_errr((char*)"Error opening file: ", (char*)"data.csv");
	std::getline(infile, line);
	while (std::getline(infile, line)) {
		size_t pos = line.find(",");
		my_price.date = line.substr(0, pos);
		my_price.price = line.substr(pos + 1);
		btc_price.push_back(my_price);
	}
}

// void find_nearest_date (Date date, std::list<price> &btc_price)
// {
// 	int year, month, day;
	
// 	year = (int)strtof(date.year.c_str(), NULL);
// 	month = (int)strtof(date.month.c_str(), NULL);
// 	day = (int)strtof(date.day.c_str(), NULL);
// 	for (std::list<price>::iterator it = btc_price.begin(); it != btc_price.end(); ++it) {
//         if (year > (int)strtof(it->date.c_str(), NULL)) {
// 			it++;
// 			continue;
// 		}
// 		else
// 			std::cout << year << std::endl;
//     }
// }

void parse_btc_amount (char *file)
{
	// std::map<amount> _btc_amount;
	// std::list<amount> btc_amount;
	std::string line;
	std::list<price> btc_price;
	amount my_amount;
	std::ifstream infile(file);
	if (!infile.good())
		throw_errr((char*)"Error opening file: ", file);
	parse_btc_price(btc_price);
	int i = 0;
	while (!infile.eof()) {
		std::getline(infile, line);
		if (line.compare("date | value") == 0 && i == 0)
			continue;
		if (get_data(my_amount, line.c_str())) {
			// my_amount = btc_amount.back();
			std::list<price>::iterator it = btc_price.begin();
			for (; it != btc_price.end(); it++) {
				// if (my_amount.date == it->date) {
				// 	float value = strtof(my_amount.value.c_str(), NULL);
				// 	float price = strtof(it->price.c_str(), NULL);
				// 	std::cout << my_amount.date << " => " << my_amount.value << " = " << value * price << std::endl;
				// 	break ;
				// }
			}
			// if (it == btc_price.end())
			// 	find_nearest_date(my_amount._date, btc_price);
		}
		i++;
	}
	infile.close();
}

int main (int ac, char **av)
{
	if (ac == 2)
		parse_btc_amount (av[1]);
	else
		throw_errr((char*)"Error: could not open file.", NULL);
	return (0);
}