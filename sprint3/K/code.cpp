#include <vector>
#include <cassert>
#include <iterator>
#include <iostream>

using Iterator = std::vector<int>::iterator;
using CIterator = std::vector<int>::const_iterator;

std::vector<int> merge(
	CIterator left_begin, CIterator left_end, 
	CIterator right_begin, CIterator right_end) {
		std::vector<int> res;
		while(left_begin != left_end && right_begin != right_end) {
			if (*left_begin < *right_begin) {
				res.push_back(*left_begin);
				++left_begin;
			} else {
				res.push_back(*right_begin);
				++right_begin;
			}
		}
		while(left_begin != left_end) {
			res.push_back(*left_begin);
			++left_begin;
		}
		while(right_begin != right_end) {
			res.push_back(*right_begin);
			++right_begin;
		}
		return res;
}

void merge_sort(Iterator begin, Iterator end) {
	if (end - begin == 1) {
		return;
	}
	int mid = (end - begin) / 2;
	std::vector<int> left (begin, begin+mid);
	std::vector<int> right (begin+mid, end);
	merge_sort(left.begin(), left.end());
	merge_sort(right.begin(), right.end());
	std::vector res = merge(left.begin(), left.end(),
						    right.begin(), right.end());	
	Iterator res_it = res.begin();
	while(begin != end) {
		*begin = *res_it;
		res_it++;
		begin++;
	}					
}
