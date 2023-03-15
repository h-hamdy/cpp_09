#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>

void	throw_errr(char *msg, char *str);
void 	get_rpn(char *str, std::stack<int> &rpn);
void	skip_space(char *str, int *i);
void	get_numbers(int &f_num, int &s_num, std::stack<int> &rpn);
bool	is_sign (char c);
void	check_rpn (char *str);

#endif