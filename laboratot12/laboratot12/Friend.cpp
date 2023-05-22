#include "Friend.h"

Friend::Friend() : Contact() {
    this->dateOfBirth = std::array<uint64_t, 3>();
    this->telephoneNumber = std::string();
    this->emailAddress = std::string();
}

Friend::Friend(const std::string& name_,
               const std::array<uint64_t, 3>& dateOfBirth_,
               const std::string& telephoneNumber_,
               const std::string& emailAddress_) : Contact(name_) {
    this->dateOfBirth = dateOfBirth_;
    this->telephoneNumber = telephoneNumber_;
    this->emailAddress = emailAddress_;
}

Friend::~Friend() {

}

std::array<uint64_t, 3> Friend::getDateOfBirth() {
    return this->dateOfBirth;
}

void Friend::setDateOfBirth(const std::array<uint64_t, 3>& dateOfBirth_) {
    this->dateOfBirth = dateOfBirth_;
}

std::string Friend::getTelephoneNumber() {
    return telephoneNumber;
}

void Friend::setTelephoneNumber(const std::string& telephoneNumber_) {
    this->telephoneNumber = telephoneNumber_;
}

std::string Friend::getEmailAddress() {
    return emailAddress;
}

void Friend::setEmailAddress(const std::string& emailAddress_) {
    this->emailAddress = emailAddress_;
}

Type Friend::getType() {
    return Type::Friend;
}
