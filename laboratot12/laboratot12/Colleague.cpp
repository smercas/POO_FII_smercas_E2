#include "Colleague.h"

Colleague::Colleague() : Contact(Type::Colleague) {
	this->telephoneNumber = std::string();
	this->company = std::string();
	this->emailAddress = std::string();
}

Colleague::Colleague(const std::string& name_,
					 const std::string& telephoneNumber_,
					 const std::string& company_,
					 const std::string& emailAddress_) : Contact(name_, Type::Colleague) {
	this->telephoneNumber = telephoneNumber_;
	this->company = company_;
	this->emailAddress = emailAddress_;
}

Colleague::~Colleague() {

}

std::string Colleague::getTelephoneNumber() {
	return this->telephoneNumber;
}

void Colleague::setTelephoneNumber(const std::string& telephoneNumber_) {
	this->telephoneNumber = telephoneNumber_;
}

std::string Colleague::getCompany() {
	return this->company;
}

void Colleague::setCompany(const std::string& company_) {
	this->company = company_;
}

std::string Colleague::getEmailAddress() {
	return this->emailAddress;
}

void Colleague::setEmailAddress(const std::string& emailAddress_) {
	this->emailAddress = emailAddress_;
}

//Type Colleague::getType() {
//	return Type::Colleague;
//}
