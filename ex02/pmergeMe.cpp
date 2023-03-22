# include "pmergeMe.hpp"

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

// void vectorMergeSort(std::vector<int> &vec)
// {

// }

// void insertionSort(int array[], int size) {
//   for (int i = 1; i < size; i++) {
//     int key = array[i];
//     int j = i - 1;

//     while (key < array[j] && j >= 0) {
//       array[j + 1] = array[j];
//       --j;
//     }
//     array[j + 1] = key;
//   }
// }

