#include <iostream>
#include "queue.h"

int main()
{
	deadrat22::Queue* q = new deadrat22::Queue();
	for (int i = 0; i < 100; i++) {
		q->enqueue(i);
	}
	for (int i = 0; i < q->size(); i++) {
		std::cout << q->first_data() << " ";
		q->dequeue();
	}
	std::cout << std::endl;
	int x;
	std::cin >> x;
	delete(q);
}

