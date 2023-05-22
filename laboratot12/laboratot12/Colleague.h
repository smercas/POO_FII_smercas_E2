#pragma once
#include "Contact.h"

class Colleague : public Contact {
	std::string telephoneNumber;
	std::string company;
	std::string emailAddress;
public:
	Colleague();
	Colleague(const std::string&, const std::string&, const std::string&, const std::string&);
	~Colleague();
	std::string getTelephoneNumber();
	void setTelephoneNumber(const std::string&);
	std::string getCompany();
	void setCompany(const std::string&);
	std::string getEmailAddress();
	void setEmailAddress(const std::string&);
	virtual Type getType() override final;
};
