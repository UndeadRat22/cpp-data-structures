#include "List.hpp"

#include <iostream>

using namespace deadrat22;

int main() {
	List* l = new List();
	for (int i = 0; i < 10; i++) {
		std::cout << "pushing " << i << std::endl;
		l->push_head(i);
	}
	for (int i = 0; i < 10; i++) {
		std::cout << i << " " << l->pop_head() << std::endl;
	}
	int x;
	std::cin >> x;
}