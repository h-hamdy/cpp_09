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
	std::exit (1);
}

bool	is_digite(char *str)
{
	for (int i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

bool check_range(char *token, int i)
{
	int num = atoi(token);
	if (i == 1 && num > 0 && num < 2024)
		return (true);
	else if (i == 2 && num > 0 && num < 13)
		return (true);
	else if (i == 3 && num > 0 && num < 32)
		return (true);
	return (false);
}

// std::string get_data(std::string line, int sign)
// {
// 	if (sign == 'd') {
// 		std::string date;

// 		for (int i = 0; line[i] != '|'; i++)
// 			date.push_back(line[i]);
// 		date.erase(date.length() - 1);
// 		int flag = 0;
// 		for (int i = 0; date[i]; i++)
// 			if (date[i] == '-')
// 				flag++;
// 		if (flag != 2)
// 			return ("");
// 		char *str = strdup(date.c_str());
// 		char* token = std::strtok(str, "-");
// 		int i = 0;
// 		while (token != NULL) {
// 			i++;
// 			if (!is_digite(token))
// 				return ("");
// 			if (!check_range(token, i))
// 				return ("");
// 			token = std::strtok(NULL, "-");
// 		}
// 		if (i != 3)
// 			return ("");
// 		delete str;
// 		return (date);
// 	}
// 	else if (sign == 'a') {
// 		std::string amount;
// 		int i = 0;
// 		while (line[i] && line[i] != '|')
// 			i++;
// 		if (line[i] == '|' && (int)strlen(line.c_str()) > i + 2)
// 		{
// 			i += 2;
// 			while (line[i]) {
// 				amount.push_back(line[i]);
// 				i++;
// 			}
// 			int value = atoi(amount.c_str());
// 			if (value > 0 && value <= 1000) {
// 				return (amount);
// 			}
// 			else
// 				return ("");
// 		}
// 		else
// 			return ("");
// 	}
// 	return ("");
// }

// void parse_btc_amount (std::map<std::string, std::string> &btc_amount, char *file)
// {
// 	std::string line;
// 	(void)btc_amount;
// 	std::ifstream infile(file);
// 		if (!infile.good())
// 			throw_errr((char*)"Error opening file: ", file);
// 	std::getline(infile, line);
// 	while (std::getline(infile, line)) {
// 		std::string d = get_data(line, 'd');
// 		if (d.empty()) {
// 			btc_amount.insert(std::pair <std::string, std::string>("", ""));
// 			// std::cout << d;
// 			continue;
// 		}
// 		std::string a = get_data(line, 'a');
// 		if (a.empty()) {
// 			btc_amount.insert(std::pair <std::string, std::string>("", ""));
// 			// std::cout << a << std::endl;
// 			continue;
// 		}
// 		btc_amount.insert(std::pair <std::string, std::string>(d, a));
// 		// std::cout << d << " " << a << std::endl;
// 	}
// 	infile.close();
// }

int main (int ac, char **av)
{
	(void)av;
	if (ac == 2)
	{
		amount btc;
		std:list<btc> my_data;
		// parse_btc_amount (btc_amount, av[1]);
		// std::map<std::string, std::string>::iterator it;
		// for (it = btc_amount.begin(); it != btc_amount.end(); ++it) {
    	// 	std::cout << it->first << " " << it->second << std::endl;
		// 	// break;
		// }
	}
	else
		throw_errr((char*)"Error: could not open file.", NULL);
	return (0);
}