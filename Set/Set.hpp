#pragma once
#include <stdexcept>
#include <vector>

namespace deadrat22 {
	template <class T>
	struct Node {
		Node<T>(const T & _value, Node* _next)
			: value(_value), next(_next) {}
		T value;
		Node* next;
	};

	template <class T>
	class Set {
	private:
		Node<T>* head;
		int count = 0;
	public:
		Set<T>() : head(nullptr), count(0){ }
		~Set<T>() {
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

		int size() const {
			return count;
		}
		
		std::vector<T> values() {
			std::vector<T> arr;
			arr.reserve(this->count);
			Node<T>* ptr = this->head;
			for (int i = 0; i < count, ptr != nullptr; ptr = ptr->next) {
				arr.push_back(ptr->value);
			}
			return arr;
		}

		Set<T>* clone() {
			Set<T>* copy = nullptr;
			try {
				copy = new Set<T>();
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

		bool contains(const T & value) {
			Node<T>* ptr = this->head;
			for (int i = 0; i < count; i++, ptr = ptr->next)
			if (ptr->value == value) {
				return true;
			}

			return false;
		}

		void add(const T & value) {
			if (this->contains(value))
				return;
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

		void remove(const T & value) {
			Node<T>* prev = nullptr;
			Node<T>* ptr = this->head;
			for (int i = 0; i < count; i++, prev = ptr, ptr = ptr->next) {
				if (ptr->value == value) {
					prev->next = ptr->next;
					delete(ptr);
					count--;
					return;
				}
			}
		}
	};
}