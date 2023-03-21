# include "pmergeMe.hpp"

void	throw_err(char *msg) 
{
	std::cerr << msg << std::endl;
	std::exit (1);
}

void	check_num(char **av)
{
	for (int i = 1; av[i]; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (!isdigit(av[i][j]) && !isspace(av[i][j]))
				throw_err ((char *)"Invalid numbers.");
		}
		// std::cout << av[i] << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac < 3)
		throw_err((char*)"Arguments less than 3.");
	check_num(av);
	int arr[ac -1];
	for (int i = 0; av[i]; i++) {
		std::cout<< "->>> " << av[i] << std::endl;
		arr[i] = std::atoi(av[i]);
		std::cout<< " thiiiis " << arr[i] << std::endl;
	}
	// for (int i = 0; i < ac - 1; i++) {
	// 	std::cout << arr[i] << std::endl;
	// }
}