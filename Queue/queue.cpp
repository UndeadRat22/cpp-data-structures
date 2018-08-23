#include "queue.h"

#include <stdexcept>

using namespace deadrat22;

Queue::Queue()
{
	this->head = this->tail = nullptr;
    this->count = 0;
}

bool Queue::empty()
{
	return this->head == nullptr;
}

void Queue::enqueue(const int& x)
{
	Node* temp = nullptr;
	try {
		temp = new Node();
	}
	catch (const std::exception& e){
		throw e;
	}
	temp->data = x;
    temp->next = nullptr;
    this->count++;

    if (this->tail == nullptr)
    {
        this->head = this->tail = temp;
        return;
    }

    this->tail->next = temp;
    this->tail = temp;
}

void Queue::dequeue()
{
	if (this->head == nullptr)
		throw new std::exception("Can't dequeue, because queue is empty!");
    Node *temp = this->head;
    this->head = this->head->next;

    if (this->head == nullptr)
        this->tail = nullptr;
    else delete(temp);
    this->count--;
}

int Queue::first_data()
{
	if (this->head == nullptr)
		throw new std::exception("Can't get data from the first in queue, because the queue is empty!");
    return this->head->data;
}

int Queue::size() {
	return this->count;
}

Queue::~Queue() {
	Node *temp = this->head->next;
	Node *curr = temp;
	while (temp != nullptr) {
		temp = curr->next;
		delete(temp);
		temp = curr;
	}
	delete(temp);
	delete(curr);
}