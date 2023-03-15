# include "BitcoinExchange.hpp"

std::string check_date (std::string date)
{
	char *str = strdup(date.c_str());
	int flag = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] == '-')
			flag++;
	if (flag != 2)
		return ("Invalid date format.");
	int i = 0;
	char *token = std::strtok(str, "-");
	while (token != NULL) {
		i++;
		if (!is_digite(token))
			return ("Invalid date format.");
		if (!check_range(token, i))
			return ("Error: too large a number.");
		token = std::strtok(NULL, "-");
	}
	if (i != 3)
		return ("Invalid date format.");
	free (str);
	return ("");
}

int get_data(std::list<amount> &btc_amount, std::string line)
{
	std::string date;
	std::string value;
	amount btc;
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
	std::string date_msg = check_date(date);
	std::string value_msg = check_value(value);
	if (date_msg != "") {
		std::cerr << date_msg << std::endl;
		return 0;
	}
	if (value_msg != "") {
		std::cerr << value_msg << std::endl;
		return 0;
	}
	btc.date = date;
	btc.value = value;
	btc_amount.push_back(btc);
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

void parse_btc_amount (char *file)
{
	std::list<amount> btc_amount;
	std::string line;
	std::list<price> btc_price;
	amount my_amount;
	std::ifstream infile(file);
	if (!infile.good())
		throw_errr((char*)"Error opening file: ", file);
	parse_btc_price(btc_price);
	std::getline(infile, line);
	while (std::getline(infile, line)) {
		if (get_data(btc_amount, line)) {
			my_amount = btc_amount.back();
			for (std::list<price>::iterator it = btc_price.begin(); it != btc_price.end(); it++) {
				if (my_amount.date == it->date) {
					float value = strtof(my_amount.value.c_str(), NULL);
					float price = strtof(it->price.c_str(), NULL);
					std::cout << my_amount.date << " => " << my_amount.value << " = " << value * price << std::endl;
					break ;
				}
			}
		}
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