#pragma once

namespace deadrat22 {
	struct Node
	{
	public:
		int data;
		struct Node* next;
	};

	class Queue
	{
	public:
		Node* head;
		Node* tail;

		Queue();
		~Queue();
		bool empty();
		void enqueue(const int& x);
		void dequeue();
		int first_data();
		int size();
	private:
		int count;
	};
}