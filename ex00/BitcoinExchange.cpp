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

bool is_valid_float(char* &str) {
	int flag = 0;
	int i = 0;

	if (str[i] == '+')
		i++;
	for (; str[i]; i++) {
		if (!isdigit(str[i]) && str[i] != '.')
			return (false);
		else if (str[0] == '.' || str[strlen(str) - 1] == '.')
			return (false);
		if (str[i] == '.' )
			flag++;
	}
	if (flag > 1)
		return (false);
	return (true);
}

bool check_range(char *token, int i)
{
	int num = std::atof(token);
	if (num == 0 && (int)strlen(token) >= 3)
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
	char *str = strdup(value.c_str());
	if (value.empty())
		return ("value doesn't exist.");
	if (!is_valid_float(str))
		return ("invalid value");
	if (!check_range(str, 4))
		return ("value should be <0 => 1000>.");
	return ("");
}
