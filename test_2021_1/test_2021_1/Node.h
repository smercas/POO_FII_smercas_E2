#pragma once
template<typename T>
class Node {
public:
	T value;
	Node* previous;
	Node* next;
	Node(const T& value) : Node(value, nullptr, nullptr) {}
	Node(const T& value, Node* previous, Node* next) {
		this->value = value;
		this->previous = previous;
		this->next = next;
	}
};