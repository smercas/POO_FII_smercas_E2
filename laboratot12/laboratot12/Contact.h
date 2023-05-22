#pragma once
#include <string>
#include <string_view>

enum class Type {
	Friend,
	Associate,
	Colleague
};

class Contact {
	std::string name;
public:
	Contact();
	Contact(const std::string&);
	virtual ~Contact();
	std::string getName();
	void setName(const std::string&);
	virtual Type getType() = 0;
};
