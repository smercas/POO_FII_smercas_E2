#include "Associate.h"

Associate::Associate() : Contact() {
	this->telephoneNumber = std::string();
}

Associate::Associate(const std::string& name_,
					 const std::string& telephoneNumber_) : Contact(name_) {
	this->telephoneNumber = telephoneNumber_;
}

Associate::~Associate() {

}

std::string Associate::getTelephoneNumber() {
	return this->telephoneNumber;
}

void Associate::setTelephoneNumber(const std::string& telephoneNumber_) {
	this->telephoneNumber = telephoneNumber_;
}

Type Associate::getType() {
	return Type::Associate;
}
