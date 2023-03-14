# include "BitcoinExchange.hpp"

void	throw_errr(char *msg, char *str)
{
	while (*msg)
		std::cerr << *msg++;
	if (str) {
		while (*str)
			std::cerr << *str++;
	}
	std::cerr << std::endl;
	exit (1);
}

bool isNumber(std::string str) {
    std::stringstream ss(str);
    double num;
    ss >> num;
    if (!ss.fail())
		return(true);
	std::cout << "Error: not a number." << std::endl;
	return (false);
}

std::string get_data(std::string line, int sign)
{
	if (sign == 'd') {
		std::string date;

		for (int i = 0; line[i] != '|'; i++)
			date.push_back(line[i]);
		date.pop_back();
		return (date);
	}
	else if (sign == 'a') {
		std::string amount;
		int i = 0;
		while (line[i] && line[i] != '|')
			i++;
		if (line[i] != '|')
			std::cout << "Error: bad input" << std::endl;
		else {
			i += 2;
			while (line[i]) {
				amount.push_back(line[i]);
				i++;
			}
			if (isNumber(amount)) {
				// std::cout << "Error: not a number." << std::endl;
				// return ("");
			}
			// if (!is_number(amount)) {
			// 	std::cout << "Error: not a positive number or it's not a number" << std::endl;
			// 	return ("");
			// }
			return (amount);
		}
	}
	return ("");
}

void parse_btc_amount (std::map<std::string, std::string> &btc_amount, char *file)
{
	std::string line;
	(void)btc_amount;
	std::ifstream infile(file);
		if (!infile.good())
			throw_errr((char*)"Error opening file: ", file);
	std::getline(infile, line);
	while (std::getline(infile, line)) {
		std::string d = get_data(line, 'd');
		if (!d.empty())
			std::cout << d;
		std::cout << " ";
		std::string a = get_data(line, 'a');
		if (!a.empty())
			std::cout << a << std::endl;
		// return ;
		// btc_amount.insert(std::pair <std::string, int>(get_date(line), get_amount(line)));
	}
	infile.close();
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		std::map<std::string, std::string> btc_amount;
		std::map<std::string, std::string> btc_price;
	
		parse_btc_amount (btc_amount, av[1]);
	}
	else
		throw_errr((char*)"Error: could not open file.", NULL);
	return (0);
}