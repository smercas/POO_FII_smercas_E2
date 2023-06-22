#pragma once
#include "Contact.h"
#include <array>
#include <cstdint>

class Friend : public Contact {
	std::array<uint64_t, 3> dateOfBirth;
	std::string telephoneNumber;
	std::string emailAddress;
public:
	Friend();
	Friend(const std::string&, const std::array<uint64_t, 3>&, const std::string&, const std::string&);
	~Friend();
	std::array<uint64_t, 3> getDateOfBirth();
	void setDateOfBirth(const std::array<uint64_t, 3>&);
	std::string getTelephoneNumber();
	void setTelephoneNumber(const std::string&);
	std::string getEmailAddress();
	void setEmailAddress(const std::string&);
	// virtual Type getType() override final;
};
