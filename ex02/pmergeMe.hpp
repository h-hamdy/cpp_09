#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <vector>


std::vector<int>	inisialize_v (char **av, int ac);
void 				vectorInsertionSort(std::vector<int> &vec);
void 				vector_merge(std::vector<int>& arr, int left, int mid, int right);
void 				vector_merge_insert(std::vector<int>& vec, int start, int end);

std::deque<int> inisialize_d(char **av, int ac);
void  			dequeInsertionSort(std::deque<int> &deq);
void 			deque_merge_insert(std::deque<int> &deq, int start, int end);
void 			deque_merge(std::deque<int>& deq, int left, int mid, int right);


#endif