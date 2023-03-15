# include "RPN.hpp"

bool	is_sign (char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void	get_numbers(int &f_num, int &s_num, std::stack<int> &rpn)
{
	s_num = rpn.top();
	rpn.pop();
	f_num = rpn.top();
	rpn.pop();
}

void	skip_space(char *str, int *i)
{
	while (str[*i] && str[*i] == ' ')
		*i = *i + 1;
}

void	check_rpn (char *str)
{
	int flag = 0;
	int i = 0;
	for (; str[i]; i++) {
		skip_space(str, &i);
		if (!isdigit(str[i]))
			throw "Error.";
			flag++;
		if (flag == 2) {
			i++;
			break ;
		}
	}
	while (str[i] && str[i] == ' ')
			i++;
	if (is_sign(str[i]))
		i++;	
	else
		throw "Error.";
	while (str[i]) {
		skip_space(str, &i);
		if (isdigit(str[i])) {
			i++;
			skip_space(str, &i);
			if (is_sign(str[i]))
				i++;
			else
				throw "Error.";
		}	
		else
			throw "Error.";
		if (str[i])
			i++;
	}
}

void get_rpn(char *str, std::stack<int> &rpn)
{
	int first_num = 0;
	int sec_num = 0;
	for (int i = 0; str[i]; i++) {
		if (isspace(str[i]))
			continue;
		if (isdigit(str[i]) && !isspace(str[i]) && !is_sign(str[i]))
			rpn.push(str[i] - '0');
		if (is_sign(str[i])) {
			get_numbers(first_num, sec_num, rpn);
			if (str[i] == '+')
				rpn.push(first_num + sec_num);
			else if (str[i] == '-')
				rpn.push(first_num - sec_num);
			else if (str[i] == '*')
				rpn.push(first_num * sec_num);
			else if (str[i] == '/')
				rpn.push(first_num / sec_num);
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		throw_errr((char*)"Invalid argument", NULL);
	std::stack<int> rpn;
	try {
		check_rpn(av[1]);
		get_rpn(av[1], rpn);
        std::cout << rpn.top() << std::endl;
    }
	catch (...) {
		std::cout << "Error" << std::endl;
	}
}