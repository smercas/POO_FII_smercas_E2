#include <iostream>
#include <random>
#include <cstdarg>
#include <vector>
#include "Sort.h"
#include "DLL.h"
Sort::Sort(unsigned long long length, long long min, long long max) : list() {
	if (min == max) {
		printf("WARNING: min is equal to max. All the values from the list will be the same.\n");
		for (unsigned long long i = 0; i < length; ++i) {
			this->list.PushLast(min);
		}
	}
	else {
		if (min > max) {
			printf("WARNING: min is bigger than max. The two values will be reversed.\n");
			std::swap(min, max);
		}
		std::random_device seed;
		std::default_random_engine generator (seed());
		std::uniform_int_distribution<long long> distribution(min, max);
		for (unsigned long long i = 0; i < length; ++i) {
			this->list.PushLast(distribution(generator));
		}
	}
}
long long* default_vector = new long long[10]{ 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
Sort::Sort() : list(10, default_vector) {
	unsigned long long counter = 0;
	/*
	while (*(vector + counter)) {
		this->list.PushLast(*(initList + counter));
	}
	/**/
}
Sort::Sort(unsigned long long length, long long* vector) : list() {
	for (unsigned long long i = 0; i < length; i++) {
		this->list.PushLast(*(vector + i));
	}
}
Sort::Sort(unsigned long long length, ...) : list() {
	va_list vl;
	va_start(vl, length);
	for (unsigned long long i = 0; i < length; i++)
	{
		this->list.PushLast(va_arg(vl, int));
	}
	va_end(vl);
}
Sort::Sort(const char* string) : list() {
	unsigned long long i = 0;
	long long number;
	long long sign = 1;
	while (*(string + i)) {
		number = 0;
		if (*(string + i) == ',') {

		}
		else if (*(string + i) == '-') {
			sign = -1;
		}
		/*
		else if (*(string + i) == '0') {
			
		}
		*/
		else {
			while (*(string + i) != ',' && *(string + i)) {
				number = number * 10 + sign * (*(string + i) - '0');
				++i;
			}
			this->list.PushLast(number);
		}
		++i;
	}
}
void Sort::InsertSort(bool ascendent) {
	for (Node* I = (this->list.GetFirst())->GetNext(); I != nullptr; I = I->GetNext()) {
		Node* J = I;
		while (J != this->list.GetFirst() && (ascendent ? J->GetValue() < J->GetPrev()->GetValue() : J->GetValue() > J->GetPrev()->GetValue())) {
			this->list.SwapValues(J, J->GetPrev());
			J = J->GetPrev();
		}
	}
}
Node* Sort::Partition(Node* first, Node* last, bool ascendent) {
	Node* I = first->GetNext();
	Node* J = last;
	while (I != J) {
		if (ascendent ? I->GetValue() <= first->GetValue() : I->GetValue() >= first->GetValue()) {
			I = I->GetNext();
		}
		else if (ascendent ? J->GetValue() >= first->GetValue() : J->GetValue() <= first->GetValue()) {
			J = J->GetPrev();
		}
		else if (ascendent ? I->GetValue() > first->GetValue() && J->GetValue() < first->GetValue() : I->GetValue() < first->GetValue() && J->GetValue() > first->GetValue()) {
			this->list.SwapValues(I, J);
		}
	}
	if (ascendent ? I->GetValue() < first->GetValue() : I->GetValue() > first->GetValue()) {
		this->list.SwapValues(I, first);
		return I;
	}
	else if (I->GetValue() == first->GetValue()) {
		return I;
	}
	else {
		this->list.SwapValues(I->GetPrev(), first);
		return I->GetPrev();
	}
}
void Sort::QuickSortHelper(Node* first, Node* last, bool ascendent) {
	if (first != last) {
		Node* p = this->Partition(first, last, ascendent);
		//this->Print();
		if (p != first) {
			QuickSortHelper(first, p->GetPrev(), ascendent);
		}
		if (p != last) {
			QuickSortHelper(p->GetNext(), last, ascendent);
		}
	}
}
void Sort::QuickSort(bool ascendent) {
	QuickSortHelper(this->list.GetFirst(), this->list.GetLast(), ascendent);
}
void Sort::BubbleSort(bool ascendent) {
	for (Node* I = this->list.GetFirst(); I != this->list.GetLast(); I = I->GetNext()) {
		for (Node* J = I->GetNext(); J != nullptr; J = J->GetNext()) {
			if ((ascendent ? I->GetValue() > J->GetValue() : I->GetValue() < J->GetValue())) {
				this->list.SwapValues(I, J);
			}
		}
	}
}
void Sort::Print() {
	if (this->list.GetLength() == 0) {
		printf("WARNING: The list is empty. Method call can't print anything.\n");
		return;
	}
	for (Node* I = this->list.GetFirst(); I != nullptr; I = I->GetNext()) {
		printf("%lld ", I->GetValue());
	}
	printf("\n");
}