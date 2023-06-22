#include <iostream>
#include "Sentence.h"

Sentence::Sentence(std::string name) {
	this->name = name;
}
void Sentence::RunAll() {
	for (Procesor* procesor : this->procesators) {
		std::cout << "Name:" << procesor->GetName() << " => " << procesor->Compute(this->name) << std::endl;
	}
}
void Sentence::ListAll() {
	for (Procesor* procesor : this->procesators) {
		std::cout << "Name:" << procesor->GetName() << std::endl;
	}
}
void Sentence::Run(std::string name) {
	for (Procesor* procesor : this->procesators) {
		if (procesor->GetName() == name) {
			std::cout << procesor->Compute(this->name) << std::endl;
		}
	}
}
Sentence& Sentence::operator+=(Procesor* procesor) {
	if (procesor) {
		this->procesators.push_back(procesor);
	}
	return *this;
}
