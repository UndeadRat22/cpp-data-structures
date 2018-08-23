#pragma once

namespace deadrat22 {
	template <class T>
	struct Node
	{
	public:
		T data;
		struct Node<T>* next;
	};

	template <class T>
	class Queue
	{
	public:
		Node<T>* head;
		Node<T>* tail;

		Queue<T>() {
			this->head = this->tail = nullptr;
			this->count = 0;
		}
		~Queue<T>() {
			Node<T>* temp = this->head->next;
			Node<T>* curr = temp;
			while (temp != nullptr) {
				temp = curr->next;
				delete(temp);
				temp = curr;
			}
			delete(temp);
			delete(curr);
		}
		bool empty() {
			return this->head == nullptr;
		}
		void enqueue(const T& val) {
			Node<T>* temp = nullptr;
			try {
				temp = new Node<T>();
			}
			catch (const std::exception& e) {
				throw e;
			}
			temp->data = val;
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
		void dequeue() {
			if (this->head == nullptr)
				throw new std::exception("Can't dequeue, because queue is empty!");
			Node<T>* temp = this->head;
			this->head = this->head->next;

			if (this->head == nullptr)
				this->tail = nullptr;
			else delete(temp);
			this->count--;
		}
		T first_data() {
			if (this->head == nullptr)
				throw new std::exception("Can't get data from the first in queue, because the queue is empty!");
			return this->head->data;
		}
		int size() {
			return this->count;
		}
	private:
		int count;
	};
}