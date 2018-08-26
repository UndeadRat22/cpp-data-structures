#include "List.hpp"

#include <iostream>

using namespace deadrat22;

int main() {
	List<int>* l = new List<int>();
	for (int i = 0; i < 10; i++) {
		std::cout << "pushing " << i << std::endl;
		l->push_head(i);
	}

	List<int>* cpy = l->clone();

	std::cout << (*cpy)[5] << (*cpy)[1]<< std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << i << " " << cpy->pop_head() << std::endl;
	}

	delete cpy;
	delete l;
	int x;
	std::cin >> x;
}