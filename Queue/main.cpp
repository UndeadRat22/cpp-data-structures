#include <iostream>
#include "queue.h"

int main()
{
	deadrat22::Queue* q = new deadrat22::Queue();
	for (int i = 0; i < 100; i++) {
		q->enqueue(i);
	}
	std::cout << q->size() << std::endl;
	while(q->size() > 0){
		std::cout << q->first_data() << " ";
		q->dequeue();
	}
	std::cout << std::endl;
	int x;
	std::cin >> x;
	delete(q);
}

