#include "Contact.h"

Contact::Contact() {
    this->name = std::string();
}

Contact::Contact(const std::string& name_) {
    this->name = name_;
}

Contact::~Contact() {

}

std::string Contact::getName() {
    return this->name;
}

void Contact::setName(const std::string& name_) {
    this->name = name_;
}
