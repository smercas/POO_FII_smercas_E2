#pragma once
#include "Node.h"
#include <cstdint>
#include <iostream>

template<typename T>
class DoubleLinkedList {
	Node<T>* first;
	Node<T>* last;
	uint64_t length;
public:
	DoubleLinkedList() {
		this->first = nullptr;
		this->last = nullptr;
		this->length = 0;
	}
	DoubleLinkedList(const T& value) {
		Node<T>* X = new Node<T>(value);
		this->first = X;
		this->last = X;
		++this->length;
	}
	~DoubleLinkedList() {
		if (this->length == 0) {
			return;
		}
		Node<T>* Y = this->first;
		Node<T>* X = Y->next;
		while (X != nullptr) {
			delete Y;
			Y = X;
			X = X->next;
		}
		delete Y;
		this->first = nullptr;
		this->last = nullptr;
		this->length = 0;
	}
	void PushOnFront(const T& value) {
		Node<T>* X;
		if (length == 0) {
			X = new Node<T>(value, nullptr, nullptr);
			this->first = X;
			this->last = X;
		}
		else {
			X = new Node<T>(value, nullptr, this->first);
			this->first->previous = X;
			this->first = X;
		}
		++this->length;
	}
	void PushOnBack(const T& value) {
		Node<T>* X;
		if (length == 0) {
			X = new Node<T>(value, nullptr, nullptr);
			this->first = X;
			this->last = X;
		}
		else {
			X = new Node<T>(value, this->last, nullptr);
			this->last->next = X;
			this->last = X;
		}
		++this->length;
	}
	T PopFromBack() {
		if (length == 0) {
			return T();
		}
		else {
			T temp = this->last->value;
			if (this->length == 1) {
				delete this->last;
				this->first = nullptr;
				this->last = nullptr;
			}
			else {
				this->last = this->last->previous;
				delete this->last->next;
				this->last->next = nullptr;
			}
			--this->length;
			return temp;
		}
	}
	uint64_t GetCount() {
		return this->length;
	}
	void PrintAll(void (*print_function) (const T&)) {
		printf("Elements: %llu =>", this->length);
		Node<T>* X = this->first;
		while (X != nullptr) {
			print_function(X->value);
			X = X->next;
		}
		printf("\n");
	}
};