# include "BitcoinExchange.hpp"

int check_line (std::string date, amount &my_amount, std::string value)
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
	my_amount.date = date;
	my_amount.value = value;
	return (1);
}

int get_data(amount &my_amount, std::string line)
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
void	parse_btc_price (std::map<std::string, std::string> &btc_price)
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
		btc_price.insert(std::pair<std::string, std::string>(my_price.date, my_price.price));
	}
}

void parse_btc_amount (char *file)
{
	std::map<std::string, std::string> btc_price;
	std::string line;
	amount my_amount;
	std::ifstream infile(file);
	if (!infile.good())
		throw_errr((char*)"Error opening file: ", file);
	parse_btc_price(btc_price);
	int i = 0;
	while (!infile.eof()) {
		std::getline(infile, line);
		if ((line.compare("date | value") == 0 && i == 0) || line.empty())
			continue;
		if (get_data(my_amount, line.c_str())) {
			std::map<std::string, std::string>::iterator it = btc_price.begin();
			for (; it != btc_price.end(); it++) {
				if (my_amount.date == it->first) {
					float value = strtof(my_amount.value.c_str(), NULL);
					float price = strtof(it->second.c_str(), NULL);
					std::cout << my_amount.date << " => " << my_amount.value << " = " << value * price << std::endl;
					break ;
				}
			}
			if (it == btc_price.end()) {
				std::map<std::string, std::string>::iterator itr;
				std::string f;
				itr = btc_price.upper_bound(my_amount.date);
				itr--;
				float value = strtof(my_amount.value.c_str(), NULL);
				float price = strtof(itr->second.c_str(), NULL);
				std::cout << itr->first << " => " << my_amount.value << " = " << value * price << std::endl;
			}
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