# include "pmergeMe.hpp"

void	throw_err(char *msg) 
{
	std::cout << msg << std::endl;
}

int main(int ac, char **av)
{
	(void)av;
	if (ac < 3)
		throw_err((char*)"Arguments less than 3.");
}