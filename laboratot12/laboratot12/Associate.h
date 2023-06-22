#pragma once
#include "Contact.h"

class Associate : public Contact {
	std::string telephoneNumber;
public:
	Associate();
	Associate(const std::string&, const std::string&);
	~Associate();
	std::string getTelephoneNumber();
	void setTelephoneNumber(const std::string&);
	// virtual Type getType() override final;
};
