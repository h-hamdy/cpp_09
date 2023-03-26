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

bool is_valid_float(std::string &str) {
	int flag = 0;
	int i = 0;

	if (str[i] == '+')
		i++;
	for (; str[i]; i++) {
		if (!isdigit(str[i]) && str[i] != '.')
			return (false);
		else if (str[0] == '.' || str[strlen(str.c_str()) - 1] == '.')
			return (false);
		if (str[i] == '.' )
			flag++;
	}
	if (flag > 1)
		return (false);
	return (true);
}

bool check_range(std::string token, int i)
{
	int num = std::atof(token.c_str());
	if (num == 0 && (int)strlen(token.c_str()) >= 3)
		return (true);
	if (i == 1 && num > 0 && num < 3000)
		return (true);
	else if (i == 2 && num > 0 && num < 13)
		return (true);
	else if (i == 3 && num > 0 && num < 32)
		return (true);
	else if (i == 4 && num > 0 && num < 1000)
		return (true);
	return (false);
}

std::string check_value (std::string value)
{
	if (value.empty())
		return ("value doesn't exist.");
	if (!is_valid_float(value))
		return ("invalid value");
	if (!check_range(value, 4))
		return ("value should be <0 => 1000>.");
	return ("");
}
