#pragma once
#include <stdexcept>
#include <vector>

namespace deadrat22 {
	template <class T1, class T2>
	struct Pair {
		Pair<T1, T2>(const T1 & k, const T2 & val) : key(k), value(val) {}
	public:
		T1 key;
		T2 value;
	};

	template <class T1, class T2>
	class Dict
	{
	public:
		Dict<T1, T2>() {
			hashmap = new std::vector<Pair<T1, T2>>();
		}
		~Dict<T1, T2>() {
			for (int i = 0; i < hashmap->size(); i++) {
				Pair<T1, T2>* pair = (*hashmap)[i];
				delete[pair];
			}
			delete hashmap;
		}
		int size() const {
			return hashmap.size();
		}
		bool key_exists(const T1 & key) {
			for (int i = 0; i < hashmap->size(); i++) {
				Pair<T1, T2>* pair = (*hashmap)[i];
				if (pair->key == key)
					return true;
			}
			return false;
		}
		void add_pair(T1 key, T2 val) {
			if key_exists(key)
				return;
			hashmap->push_back(new Pair<T1, T2>(key, val));
		}

		T2 value_for(T1 key) const {
			for (int i = 0; i < hashmap->size(); i++) {
				Pair<T1, T2>* pair = (*hashmap)[i];
				if (pair->key == key) {
					return pair->value;
				}
			}
			throw new std::exception("deadrat22::value_for() tried to find value with non-existent key");
		}
	private:
		std::vector<Pair<T1, T2>*>* hashmap;
	};
}