#include "Contact.h"

Contact::Contact() {
    this->name = std::string();
    this->type = Type();
}

Contact::Contact(const Type& type_) {
    this->name = std::string();
    this->type = type_;
}

Contact::Contact(const std::string& name_) {
    this->name = name_;
    this->type = Type();
}

Contact::Contact(const std::string& name_, const Type& type_) {
    this->name = name_;
    this->type = type_;
}

//Contact::~Contact() {
//
//}
//
//std::string Contact::getName() {
//    return this->name;
//}
//
//void Contact::setName(const std::string& name_) {
//    this->name = name_;
//}
