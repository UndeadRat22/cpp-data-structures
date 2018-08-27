#include <iostream>
#include "Set.hpp"

int main() {
	deadrat22::Set<int>* set = new deadrat22::Set<int>();
	for (int i = 0; i < 10; i++) {
		set->add(i);
	}
	std::vector<int> vals = set->values();
	int size = set->size();
	for (int i = 0; i < size; i++) {
		std::cout << vals[i] << " ";
	}
	std::cout << std::endl;
	int x;
	std::cin >> x;
	delete set;
}