#include "Node.h"

Node::Node(long long value) : Node(value, nullptr, nullptr) {

}
Node::Node() : Node(0) { }
Node::Node(long long value, Node* prev, Node* next) {
	this->value = value;
	this->prev = prev;
	this->next = next;
}
Node::Node(const Node& to_copy) {
	this->value = to_copy.value;
	this->prev = to_copy.prev;
	this->next = to_copy.next;
}
long long Node::GetValue() {
	return this->value;
}
void Node::SetValue(long long value) {
	this->value = value;
}
Node* Node::GetPrev() {
	return this->prev;
}
void Node::SetPrev(Node* prev) {
	this->prev = prev;
}
Node* Node::GetNext() {
	return this->next;
}
void Node::SetNext(Node* next) {
	this->next = next;
}