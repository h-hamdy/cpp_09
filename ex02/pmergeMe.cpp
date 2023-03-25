# include "pmergeMe.hpp"

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

void vectorInsertionSort(std::vector<int> &vec)
{
	int key;
	for (int i = 1; i < (int)vec.size(); i++) {
		key = vec[i];
		int j = i -1;
		for (; j >= 0 && key < vec[j]; j--)
			vec[j + 1] = vec[j];
		vec[j + 1] = key;
	}
}

void  dequeInsertionSort(std::deque<int> &deq)
{
	int key;
	for (int i = 1; i < (int)deq.size(); i++) {
		key = deq[i];
		int j = i -1;
		for (; j >= 0 && key < deq[j]; j--)
			deq[j + 1] = deq[j];
		deq[j + 1] = key;
	}
}

void vector_merge(std::vector<int>& vec, int left, int mid, int right) {
    std::vector<int> left_arr(mid - left + 1);
    std::vector<int> right_arr(right - mid);

    for (int i = 0; i < (int)left_arr.size(); i++)
        left_arr[i] = vec[left + i];

    for (int i = 0; i < (int)right_arr.size(); i++)
        right_arr[i] = vec[mid + 1 + i];

    int i = 0, j = 0, k = left;
    for (; i < (int)left_arr.size() && j < (int)right_arr.size(); k++) {
        if (left_arr[i] < right_arr[j]) {
            vec[k] = left_arr[i];
            i++;
        }
		else {
            vec[k] = right_arr[j];
            j++;
        }
    }

    for (; i < (int)left_arr.size(); i++, k++)
        vec[k] = left_arr[i];

   for (; j < (int)right_arr.size(); j++, k++)
        vec[k] = right_arr[j];
}

void vector_merge_insert(std::vector<int>& vec, int start, int end) {
	if (end - start > 5)
	{
		int q = (start + end) / 2;
		vector_merge_insert(vec, start, q);
		vector_merge_insert(vec, q + 1, end);
		vector_merge(vec, start, q, end);
	}
	else
		vectorInsertionSort(vec);
}

void deque_merge(std::deque<int>& deq, int left, int mid, int right) {
    std::vector<int> left_arr(mid - left + 1);
    std::vector<int> right_arr(right - mid);

    for (int i = 0; i < (int)left_arr.size(); i++)
        left_arr[i] = deq[left + i];

    for (int i = 0; i < (int)right_arr.size(); i++)
        right_arr[i] = deq[mid + 1 + i];

    int i = 0, j = 0, k = 0;
    for (; i < (int)left_arr.size() && j < (int)right_arr.size(); k++) {
        if (left_arr[i] <= right_arr[j]) {
            deq[k] = left_arr[i];
            i++;
        }
		else {
            deq[k] = right_arr[j];
            j++;
        }
    }

    for (; i < (int)left_arr.size(); i++, k++)
        deq[k] = left_arr[i];

   for (; j < (int)right_arr.size(); j++, k++)
        deq[k] = right_arr[j];

}

void deque_merge_insert(std::deque<int> &deq, int start, int end) {
	if (end - start > 5)
	{
		int q = (start + end) / 2;
		deque_merge_insert(deq, start, q);
		deque_merge_insert(deq, q + 1, end);
		deque_merge(deq, start, q, end);
	}
	else
		dequeInsertionSort(deq);
}
