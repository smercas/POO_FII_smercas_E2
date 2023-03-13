#pragma once
#include "Node.h"

class DLL {
	Node* first;
	Node* last;
	unsigned long long length;
	void SetLength(unsigned long long);
	bool AddLength(unsigned long long);
	bool SubLength(unsigned long long);
	bool IncLength();
	bool DecLength();
	void SetFirst(Node*);
	void SetLast(Node*);
public:
	DLL();
	DLL(const Node&);
	DLL(long long);
	DLL(unsigned long long, long long*);
	~DLL();
	unsigned long long GetLength();
	bool IsEmpty();
	bool IsFull();
	Node* GetPos(unsigned long long);
	Node* GetFirst();
	Node* GetLast();
	bool PushPos(long long, unsigned long long);
	bool PushFirst(long long);
	bool PushLast(long long);
	bool PopPos(unsigned long long);
	bool PopFirst();
	bool PopLast();
	long long GetPosValue(unsigned long long);
	long long GetFirstValue();
	long long GetLastValue();
	void SwapValues(Node*, Node*);
	void Delete();
};