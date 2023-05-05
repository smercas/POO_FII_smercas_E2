#pragma once
template <typename k, typename v>
class Node {
public:
	k key;
	v value;
	Node* next;
	Node(const k& key, const v& value) : Node(nullptr, key, value, nullptr) {}
	Node(const k& key, const v& value, Node* next) : Node(nullptr, key, value, next) {}
	Node(Node* prev, const k& key, const v& value) : Node(prev, key, value, nullptr) {}
	Node(Node* prev, const k& key, const v& value, Node* next) {
		this->key = key;
		this->value = value;
		this->next = next;
		if (prev != nullptr) {
			prev->next = this;
		}
	}
	~Node() {
		this->next = nullptr;
	}
	Node* n() {
		return this->next;
	}
	k& k() {
		return this->key;
	}
	v& v() {
		return this->value;
	}
};