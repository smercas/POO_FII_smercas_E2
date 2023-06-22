#pragma once
#include <string>

enum class Type {
	Friend,
	Associate,
	Colleague
};

class Contact {
protected:
	Contact();
	Contact(const Type&);
	Contact(const std::string&);
	Contact(const std::string&, const Type&);
public:
	std::string name;
	Type type;
	/*virtual ~Contact();
	std::string getName();
	void setName(const std::string&);
	virtual Type getType() = 0;*/
};
