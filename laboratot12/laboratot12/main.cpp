#include <iostream>
#include <cstdint>
#include "Agenda.h"

int32_t main() {
	Agenda a;
	//Friend f = Friend(birthday, number, email);
	Friend f = Friend("Mercas Stefan-Alexandru", {28, 3, 2003}, "0746 615 394", "smercas@gmail.com");
	a.addContact(f);
	std::cout << (*a.getFriends().begin())->getName() << std::endl;
}