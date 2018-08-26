#pragma once
#include <stdexcept>

namespace deadrat22 {
	struct Node {
		Node(int _value, Node* _next) 
		: value(_value), next(_next){}
		int value;
		Node* next;
	};

	class List {
	private:
		Node* head;
		int count = 0;
	public:
		List() {
			this->head = nullptr;
		}
		~List() {

		}

		int size() {
			return count;
		}

		List* clone() {
			List* copy = new List();
			return copy;
		}

		void push_head(const int & value) {
			//no elems
			try {
				if (this->head == nullptr) {
					this->head = new Node(value, nullptr);
					return;
				}
				else {
					Node* new_head = new Node(value, this->head);
					this->head = new_head;
				}
			} 
			catch (const std::bad_alloc & e) {
				throw e;
			}
		}

		int pop_head() {
			Node* new_head = this->head->next;
			int out = this->head->value;
			delete(this->head);
			this->head = new_head;
			return out;
		}
	};
}