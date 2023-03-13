#include <iostream>
#include "DLL.h"
#define GET_NODE_LIST_IS_EMPTY_WARNING printf("WARNING: The list is empty. Can't phisycally return any nodes, so the method call will return a null pointer.\n")
#define PUSH_LIST_IS_FULL_ERROR printf("ERROR: The list is full. The passed value can't be added so it won't be. The list remains unchanged.\n")
#define POP_LIST_IS_EMPTY_ERROR printf("ERROR: The list is empty. No elements can be removed since none exist. The list remains unchanged.\n")
#define GET_VALUE_LIST_IS_EMPTY_ERROR printf("WARNING: The list is empty. Can't phisycally return any values, so the method call will return 0.\n")
DLL::DLL() {
	this->SetFirst(nullptr);
	this->SetLast(nullptr);
	this->SetLength(0);
}
DLL::DLL(const Node& to_copy) {
	this->SetFirst(new Node(to_copy));
	this->SetLast(this->GetFirst());
	this->SetLength(1);
}
DLL::DLL(long long first_value) {
	this->SetFirst(new Node(first_value, nullptr, nullptr));
	this->SetLast(this->GetFirst());
	this->SetLength(1);
}
DLL::DLL(unsigned long long count, long long* values) : DLL() {
	for (unsigned long long i = 0; i < count; ++i) {
		this->PushLast(*(values + i));
	}
}
DLL::~DLL() {
	this->Delete();
}
void DLL::SetLength(unsigned long long length) {
	this->length = length;
}
bool DLL::AddLength(unsigned long long to_add) {
	if (this->GetLength() >= this->GetLength() + to_add) {
		return false;
	}
	this->SetLength(this->GetLength() + to_add);
	return true;
}
bool DLL::SubLength(unsigned long long to_subtract) {
	if (this->GetLength() < to_subtract) {
		return false;
	}
	this->SetLength(this->GetLength() - to_subtract);
	return true;
}
bool DLL::IncLength() {
	return this->AddLength(1);
}
bool DLL::DecLength() {
	return this->SubLength(1);
}
void DLL::SetFirst(Node* first) {
	this->first = first;
}
void DLL::SetLast(Node* last) {
	this->last = last;
}
unsigned long long DLL::GetLength() {
	return this->length;
}
bool DLL::IsEmpty() {
	return this->GetLength() == 0;
}
bool DLL::IsFull() {
	return this->GetLength() > this->GetLength() + 1;
}
Node* DLL::GetPos(unsigned long long position) {
	if (this->IsEmpty()) {
		GET_NODE_LIST_IS_EMPTY_WARNING;
		return 0;
	}
	if (position == 0) {
		return this->GetFirst();
	}
	if (position >= this->GetLength()) {
		printf("WARNING: positon given (%llu) is greater than the last position (%llu). Will return the last node.\n", position, this->length - 1);
		return this->GetLast();
	}
	if (position == this->GetLength() - 1) {
		return this->GetLast();
	}
	Node* nodeCounter = this->GetFirst();
	unsigned long long posCounter = 0;
	while (posCounter < position) {
		nodeCounter = nodeCounter->GetNext();
		++posCounter;
	}
	return nodeCounter;
}
Node* DLL::GetFirst() {
	if (this->IsEmpty()) {
		GET_NODE_LIST_IS_EMPTY_WARNING;
	}
	return this->first;
}
Node* DLL::GetLast() {
	if (this->IsEmpty()) {
		GET_NODE_LIST_IS_EMPTY_WARNING;
	}
	return this->last;
}
bool DLL::PushPos(long long value, unsigned long long position) {
	if (this->IsFull()) {
		PUSH_LIST_IS_FULL_ERROR;
		return false;
	}
	if (position == 0) {
		return this->PushFirst(value);
	}
	if (position > this->GetLength()) {
		printf("WARNING: positon given (%llu) is greater than the last position (%llu). Value will be placed on the last position.\n", position, this->length);
		return this->PushLast(value);
	}
	if (position == this->GetLength()) {
		return this->PushLast(value);
	}
	Node* X = new Node(value, nullptr, nullptr);
	Node* nodeCounter = this->GetFirst();
	unsigned long long posCounter = 0;
	while (posCounter < position) {
		nodeCounter = nodeCounter->GetNext();
		++posCounter;
	}
	X->SetNext(nodeCounter);
	X->SetPrev(nodeCounter->GetPrev());
	(nodeCounter->GetPrev())->SetNext(X);
	nodeCounter->SetPrev(X);
	this->IncLength();
	return true;
	/*
	if the position is k and the length is n, the element will be placed in the following way:
	before:
		A0, ..., Ak-1, Ak, ..., An-1
	after:
		A0, ..., Ak-1, NEW ELEMENT, Ak, ..., An-1

	if k is 0, then the element will be placed in the front/first position:
	before:
		A0, ..., An-1
	after:
		New ELEMENT, A0, ..., An-1
	if k is n, then the element will be placed in the back/last position:
	before:
		A0, ..., An-1
	after:
		A0, ..., An-1, NEW ELEMENT
	*/
}
bool DLL::PushFirst(long long value) {
	if (this->IsFull()) {
		PUSH_LIST_IS_FULL_ERROR;
		return false;
	}
	/*
	if (this->IsEmpty()) {
		Node* X = new Node(value, nullptr, nullptr);
		this->SetFirst(X);
		this->SetLast(X);
	}
	else {
		Node* X = new Node(value, nullptr, this->GetFirst());
		(this->GetFirst())->SetPrev(X);
		this->SetFirst(X);
	}
	this->IncLength();
	return true;
	*/ //the "normal" way of doing this
	Node* X = new Node(value, nullptr, (this->IsEmpty() ? nullptr : this->GetFirst()));
	if (!this->IsEmpty()) {
		(this->GetFirst())->SetPrev(X);
	}
	this->SetFirst(X);
	if (this->IsEmpty()) {
		this->SetLast(X);
	}
	this->IncLength();
	return true;
}
bool DLL::PushLast(long long value) {
	if (this->IsFull()) {
		PUSH_LIST_IS_FULL_ERROR;
		return false;
	}
	/*
	if (this->IsEmpty()) {
		Node* X = new Node(value, nullptr, nullptr);
		this->SetLast(X);
		this->SetFirst(X);
	}
	else {
		Node* X = new Node(value, this->GetLast(), nullptr);
		(this->GetLast())->SetNext(X);
		this->SetLast(X);
	}
	this->IncLength();
	return true;
	*/ //the "normal way of doing this
	Node* X = new Node(value, (this->IsEmpty() ? nullptr : this->GetLast()), nullptr);
	if (!this->IsEmpty()) {
		(this->GetLast())->SetNext(X);
	}
	this->SetLast(X);
	if (this->IsEmpty()) {
		this->SetFirst(X);
	}
	this->IncLength();
	return true;
}
bool DLL::PopPos(unsigned long long position) {
	if (this->IsEmpty()) {
		POP_LIST_IS_EMPTY_ERROR;
		return false;
	}
	if (position == 0) {
		return this->PopFirst();
	}
	if (position >= this->GetLength()) {
		printf("WARNING: positon given (%llu) is greater or equal to the last position (%llu). The last element will be removed.\n", position, this->length);
		return this->PopLast();
	}
	if (position == this->GetLength() - 1) {
		return this->PopLast();
	}
	Node* nodeCounter = this->GetFirst();
	unsigned long long posCounter = 0;
	while (posCounter < position) {
		nodeCounter = nodeCounter->GetNext();
		++posCounter;
	}
	(nodeCounter->GetPrev())->SetNext(nodeCounter->GetNext());
	(nodeCounter->GetNext())->SetPrev(nodeCounter->GetPrev());
	delete nodeCounter;
	this->DecLength();
	/*
	if the position is k and the length is n, the element will be removed in the following way:
	before:
		A0, ..., Ak-1, Ak, Ak+1, ..., An-1
	after:
		A0, ..., Ak-1, Ak+1, ..., An-1

	if k is 0, then the element from the front/first position will be removed:
	before:
		A0, ..., An-1
	after:
		A1, ..., An-1
	if k is n-1, then the element from the back/last position will be removed:
	before:
		A0, ..., An-1
	after:
		A0, ..., An-2
	*/
}
bool DLL::PopFirst() {
	if (this->IsEmpty()) {
		POP_LIST_IS_EMPTY_ERROR;
		return false;
	}
	this->SetFirst((this->GetFirst())->GetNext());
	delete (this->GetFirst())->GetPrev();
	(this->GetFirst())->SetPrev(nullptr);
	return true;
}
bool DLL::PopLast() {
	if (this->IsEmpty()) {
		POP_LIST_IS_EMPTY_ERROR;
		return false;
	}
	this->SetLast((this->GetLast())->GetPrev());
	delete (this->GetLast())->GetNext();
	(this->GetLast())->SetNext(nullptr);
	return true;
}
long long DLL::GetPosValue(unsigned long long position) {
	if (this->IsEmpty()) {
		GET_VALUE_LIST_IS_EMPTY_ERROR;
		return 0;
	}
	if (position == 0) {
		return (this->GetFirst())->GetValue();
	}
	if (position >= this->GetLength()) {
		printf("WARNING: Positon given (%llu) is greater than the last position (%llu). Will return the last value.\n", position, this->length - 1);
		return (this->GetLast())->GetValue();
	}
	if (position == this->GetLength()) {
		return (this->GetLast())->GetValue();
	}
	Node* nodeCounter = this->GetFirst();
	unsigned long long posCounter = 0;
	while (posCounter < position) {
		nodeCounter = nodeCounter->GetNext();
		++posCounter;
	}
	return nodeCounter->GetValue();
	/*
	if the position is k and the length is n, the method will returnthe k-th element:
	before:
		A0, ..., An-1
	after:
		Ak

	if k is 0, then the method will return the k-th element:
	before:
		A0, ..., An-1
	after:
		A0
	if k is n-1, then the method will return the k-th element:
	before:
		A0, ..., An-1
	after:
		An-1
	*/
}
long long DLL::GetFirstValue() {
	if (this->IsEmpty()) {
		GET_VALUE_LIST_IS_EMPTY_ERROR;
		return 0;
	}
	else {
		return (this->GetFirst())->GetValue();
	}
}
long long DLL::GetLastValue() {
	if (this->IsEmpty()) {
		GET_VALUE_LIST_IS_EMPTY_ERROR;
		return 0;
	}
	else {
		return (this->GetLast())->GetValue();
	}
}
void DLL::SwapValues(Node* A, Node* B) {
	long long aux = A->GetValue();
	A->SetValue(B->GetValue());
	B->SetValue(aux);
}
void DLL::Delete() {
	if (this->IsEmpty()) {
		printf("WARNING: The list is empty. Method call can't delete anything.\n");
		return;
	}
	Node* D = this->GetFirst();
	if (this->GetLength() == 1) {
		delete D;
	}
	else {
		for (Node* I = (this->GetFirst())->GetNext(); I != nullptr; I = I->GetNext()) {
			delete D;
			D = I;
		}
		delete D;
	}
	this->SetFirst(nullptr);
	this->SetLast(nullptr);
	this->SetLength(0);
}