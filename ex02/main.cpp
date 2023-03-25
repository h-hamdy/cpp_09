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
			if (j == 0 && av[i][j] == '+')
				continue;
			if (!isdigit(av[i][j]) && !isspace(av[i][j]))
				throw_err ((char *)"Invalid numbers.");
		}
	}
}

void	Sort_vector(char **av, int ac)
{
	std::vector<int> vec = inisialize_v(av, ac);
	vector_merge_insert(vec, 0, vec.size());
	std::vector<int>::iterator it = vec.begin();
	int i = 0;
	std::cout << "after: ";
	for (; it != vec.end(); ++it) {
		// if (i < 5)
			std::cout << *it << " ";
		// else {
		// 	std::cout << "[...]" << std::endl;
		// 	break;
		// }
		i++;
	}
	std::cout << std::endl;

}

void	Sort_deque(char **av, int ac)
{
	std::deque<int> deq = inisialize_d(av, ac);
	deque_merge_insert(deq, 0, deq.size());
}

void	Before_sort(char **av)
{
	// int count = 0;
	std::cout << "Before: ";
	for (int i = 1; av[i]; i++) {
		// if (count < 5)
			std::cout << av[i] << " ";
		// else {
		// 	break;
		// }
		// count++;

	}
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	if (ac < 3)
		throw_err((char*)"Arguments less than 3.");
	check_num(av);
	Before_sort(av);
	Sort_vector(av, ac);
	Sort_deque(av, ac);
}