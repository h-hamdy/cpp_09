# include "RPN.hpp"

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