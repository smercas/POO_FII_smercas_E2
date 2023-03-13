#pragma once
#include "DLL.h"
class Sort {
	DLL list;
	Node* Partition(Node*, Node*, bool);
	void QuickSortHelper(Node*, Node*, bool);
public:
	Sort(unsigned long long, long long, long long);
	Sort();
	Sort(unsigned long long, long long*);
	Sort(unsigned long long, ...);
	Sort(const char*);
	void InsertSort(bool = true);
	void QuickSort(bool = true);
	void BubbleSort(bool = true);
	void Print();
};