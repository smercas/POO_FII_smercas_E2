#pragma once
#include <vector>
#include "Entry.h"

class Database {
private:
	std::vector<Entry*> entries;
public:
	Database& operator+=(Entry*);
	Database& operator-=(std::string);
	std::vector<Entry*>::iterator begin();
	std::vector<Entry*>::iterator end();
	void Print();
};
