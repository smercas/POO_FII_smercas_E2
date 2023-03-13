#include "Sort.h"

void main() {
	Sort* A = new Sort(10, 0, 9);
	Sort* B = new Sort();
	long long v[10] = { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 };
	Sort* C = new Sort(10, v);
	Sort* D = new Sort(10, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39);
	Sort* E = new Sort("-1234543210,-5,-0,0,5,11");
	A->Print();
	A->InsertSort();
	A->Print();
	B->Print();
	C->Print();
	D->Print();
	E->Print();
}