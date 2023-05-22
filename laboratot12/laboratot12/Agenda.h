#pragma once
#include <deque>
#include <vector>
#include "Contact.h"
#include "Friend.h"

class Agenda {
	std::vector<Contact*> contacts;
public:
	Agenda();
	Agenda(std::vector<Contact*>);
	~Agenda();
	Contact* searchContact(const std::string&);
	std::vector<Friend*> getFriends();
	void deleteContact(const std::string&);
	void addContact(Contact&);
};
