#pragma once
class Node {
	long long value;
	Node* prev;
	Node* next;
public:
	Node(long long);
	Node();
	Node(long long, Node*, Node*);
	Node(const Node&);
	long long GetValue();
	void SetValue(long long);
	Node* GetPrev();
	void SetPrev(Node*);
	Node* GetNext();
	void SetNext(Node*);
};