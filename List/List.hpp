#pragma once
#include <stdexcept>

namespace deadrat22 {
	template <class T>
	struct Node {
		Node<T>(T _value, Node* _next) 
		: value(_value), next(_next){}
		T value;
		Node* next;
	};

	template <class T>
	class List {
	private:
		Node<T>* head;
		int count = 0;
	public:
		List<T>() {
			this->head = nullptr;
			this->count = 0;
		}
		~List<T>() {
			//empty list:
			if (head == nullptr) {
				return;
			}	
			Node<T>* next = nullptr;
			while (this->head != nullptr) {
				next = this->head->next;
				delete(this->head);
				this->head = next;
			}
		}

		int size() {
			return count;
		}

		List<T>* clone() {
			List<T>* copy = nullptr;
			try {
				copy = new List<T>();
				if ((count == 0) || (head == nullptr))
					return copy;
				Node<T>** ptr = &(this->head);
				for (int i = 0; (*ptr) != nullptr; ptr = &((*ptr)->next))
					copy->push_head((*ptr)->value);
			}
			catch (const std::bad_alloc & e) {
				throw e;
			}
			return copy;
		}

		void push_head(const T & value) {
			try {
				if (this->head == nullptr) {
					this->head = new Node<T>(value, nullptr);
				}
				else {
					Node<T>* new_head = new Node<T>(value, this->head);
					this->head = new_head;
				}
				count++;
			} 
			catch (const std::bad_alloc & e) {
				throw e;
			}
		}

		T pop_head() {
			Node<T>* new_head = this->head->next;
			T out = this->head->value;
			delete(this->head);
			this->head = new_head;
			count--;
			return out;
		}
	};
}