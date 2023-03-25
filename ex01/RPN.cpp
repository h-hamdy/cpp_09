# include "RPN.hpp"

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

void	get_numbers(int &f_num, int &s_num, std::stack<int> &rpn)
{
	s_num = rpn.top();
	rpn.pop();
	f_num = rpn.top();
	rpn.pop();
}

bool	is_sign (char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void	skip_space(char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		*i = *i + 1;
}

void get_rpn(char *str, std::stack<int> &rpn)
{
	int first_num = 0;
	int sec_num = 0;
	char sign;
	char *n_str = removeSpaces(str);
	int i = 0;
	while (n_str[i])
	{
		if (isdigit(n_str[i]) && !is_sign(n_str[i])) {
			rpn.push(n_str[i] - '0');
			i++;
			continue;
		}
		if (rpn.size() >= 2) {
			sign = n_str[i];
			get_numbers(first_num, sec_num, rpn);
			if (sign == '+')
				rpn.push(first_num + sec_num);
			else if (sign == '-')
				rpn.push(first_num - sec_num);
			else if (sign == '*')
				rpn.push(first_num * sec_num);
			else if (sign == '/')
				rpn.push(first_num / sec_num);
		}
		i++;
	}
}

char* removeSpaces(char* str)
{
    char* newStr = new char[std::strlen(str) + 1];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            newStr[j] = str[i];
            j++;
        }
    }
    newStr[j] = '\0';

    return newStr;
}

void	check_rpn (char *str)
{
	for (int i = 1; str[i]; i++) {
		if (!isspace(str[i]) && !isdigit(str[i]) && !is_sign(str[i]))
			throw "Error.";
	}
}