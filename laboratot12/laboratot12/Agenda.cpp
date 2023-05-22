#include "Agenda.h"

Agenda::Agenda() {
	this->contacts = std::vector<Contact*>();
}

Agenda::Agenda(std::vector<Contact*> contacts_) {
	this->contacts = contacts_;
}

Agenda::~Agenda() {

}

Contact* Agenda::searchContact(const std::string& name) {
	for (auto contact : this->contacts) {
		if (contact->getName() == name) {
			return contact;
		}
	}
	return nullptr;
}

std::vector<Friend*> Agenda::getFriends() {
	std::vector<Friend*> friends = std::vector<Friend*>();
	for (auto& contact : this->contacts) {
		if (contact->getType() == Type::Friend) {
			friends.push_back(dynamic_cast<Friend*>(contact));
		}
	}
	return friends;
}

void Agenda::deleteContact(const std::string& name) {
	std::vector<Contact*>::iterator contact = this->contacts.begin();
	while (contact != this->contacts.end()) {
		if ((*contact)->getName() == name) {
			this->contacts.erase(contact);
		}
		++contact;
	}
}

void Agenda::addContact(Contact& contact) {
	this->contacts.push_back(&contact);
}
