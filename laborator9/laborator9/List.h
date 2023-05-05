#pragma once
#include <cstdint>
#include <cstring>
#include "Node.h"

template <typename k, typename v, class e = std::equal_to<v>>
class List {
	Node<k, v>* first;
	Node<k, v>* last;
	uint64_t length;
public:
	List() {
		this->first = nullptr;
		this->last = nullptr;
		this->length = 0;
	}
	List(const k& key, const v& value) {
		Node<k, v>* X = new Node<k, v>(key, value);
		this->first = X;
		this->last = X;
		this->length = 1;
	};
	~List() {
		if (this->length != 0) {
			Node<k, v>* I = this->first;
			Node<k, v>* J = this->first->n();
			while (J != nullptr) {
				delete I;
				I = J;
				J = J->n();
			}
			delete I;
			this->first = nullptr;
			this->last = nullptr;
			this->length = 0;
		}
	}
	Node<k, v>& add(const k& key) {
		Node<k, v>* X = new Node<k, v>(this->last, key, v());
		this->last = X;
		if (this->length == 0) {
			this->first = X;
		}
		++this->length;
		return *this->last;
	}
	void remove() {
		if (this->length > 0) {
			Node<k, v>* I = this->first;
			this->first = this->first->n();
			--this->length;
			delete I;
		}
	}
	Node<k, v>* get(const k& key) {
		Node<k, v>* I = this->first;
		while (I != nullptr && !e{}(I->k(), key)) {
			I = I->n();
		}
		return I;
	}
	Node<k, v>* f() {
		return this->first;
	}
	Node<k, v>* l() {
		return this->last;
	}
	uint64_t len() {
		return this->length;
	}
};