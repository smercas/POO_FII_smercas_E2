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
		if (contact->name == name) {
			return contact;
		}
	}
	return nullptr;
}

std::vector<Friend*> Agenda::getFriends() {
	std::vector<Friend*> friends = std::vector<Friend*>();
	for (auto& contact : this->contacts) {
		if (contact->type == Type::Friend) {
			friends.push_back(static_cast<Friend*>(contact));
		}
	}
	return friends;
}

void Agenda::deleteContact(const std::string& name) {
	std::vector<Contact*>::iterator contact = this->contacts.begin();
	while (contact != this->contacts.end()) {
		if ((*contact)->name == name) {
			this->contacts.erase(contact);
		}
		++contact;
	}
}

void Agenda::addContact(Contact& contact) {
	this->contacts.push_back(&contact);
}
