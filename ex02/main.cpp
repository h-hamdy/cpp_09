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
	}
}

std::vector<int> inisialize_v (char **av, int ac) {
	std::vector<int> vec;
	for (int i = 1; i < ac; i++)
		vec.push_back(std::atoi(av[i]));
	return (vec);
}

std::deque<int> inisialize_d(char **av, int ac) {
	std::deque<int> deq;
	for (int i = 1; i < ac; i++)
		deq.push_back(std::atoi(av[i]));
	return (deq);
}

void	Sort_vector(char **av, int ac)
{
	std::vector<int> vec = inisialize_v(av, ac);
	// vectorInsertionSort(vec);
	// std::vector<int>::iterator it = vec.begin();
	// for (; it != vec.end(); ++it) {
	// 	std::cout << "vec " << *it << std::endl;
	// }
}

void	Sort_deque(char **av, int ac)
{
	std::deque<int> deq = inisialize_d(av, ac);
	// dequeInsertionSort(deq);
	// std::deque<int>::iterator it = deq.begin();
	// for (; it != deq.end(); ++it) {
	// 	std::cout << "deque " << *it << std::endl;
	// }
}

int main(int ac, char **av)
{
	if (ac < 3)
		throw_err((char*)"Arguments less than 3.");
	check_num(av);
	Sort_vector(av, ac);
	Sort_deque(av, ac);
}