#include <iostream>
#include "Database.h"

Database& Database::operator+=(Entry* entry) {
	entries.push_back(entry);
	return *this;
}
Database& Database::operator-=(std::string name) {
	uint64_t index = 0;
	std::vector<Entry*>::iterator it = this->entries.begin();
	while (it != this->entries.end()) {
		if ((*it)->GetName() == name) {
			this->entries.erase(it);
			it = entries.begin() + index;
		}
		else {
			++it;
			++index;
		}
	}
	return *this;
}
std::vector<Entry*>::iterator Database::begin() {
	return this->entries.begin();
}
std::vector<Entry*>::iterator Database::end() {
	return this->entries.end();
}
void Database::Print() {
	for (Entry* entry : this->entries) {
		std::cout << entry->GetName() << " = ";
		entry->Print();
		std::cout << ";";
	}
	std::cout << std::endl;
}
