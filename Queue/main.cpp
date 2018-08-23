#include <iostream>
#include "queue.hpp"

using namespace deadrat22;

int main()
{
	Queue<int>* q = new Queue<int>();
	for (int i = 0; i < 100; i++) {
		q->enqueue(i);
	}
	while (!q->empty()) {
		std::cout << q->first_data() << " ";
		q->dequeue();
	}
	std::cout << std::endl;
	int x;
	std::cin >> x;
	delete(q);
}

