#include <iostream>
#include "Student.h"

Student::Student() {
	this->name = "";
	this->mathematics = 1;
	this->english = 1;
	this->history = 1;
}
const char* Student::getName() {
	return this->name;
}
void Student::setName(const char* name) {
	for (int i = 0; i < strlen(name); i++) {
		if (strchr("1234567890=,./;'[]\\!@#$%^&*()_+<>?:\"{}|", *(name + i))) {
			printf("Error, wacky name: maybe try sending in a normal name.\n");
			return;
		}
	}
	this->name = name;
}
float Student::getMathematicsGrade() {
	return this->mathematics;
}
void Student::setMathematicsGrade(float mathematics) {
	if (mathematics < 1 || mathematics > 10) {
		printf("Error, invalid grade: pass in a value included in [1, 10].\n");
		return;
	}
	this->mathematics = mathematics;
}
float Student::getEnglishGrade() {
	return this->english;
}
void Student::setEnglishGrade(float english) {
	if (english < 1 || english > 10) {
		printf("Error, invalid grade: pass in a value included in [1, 10].\n");
		return;
	}
	this->english = english;
}
float Student::getHistoryGrade() {
	return this->history;
}
void Student::setHistoryGrade(float history) {
	if (history < 1 || history > 10) {
		printf("Error, invalid grade: pass in a value included in [1, 10].\n");
		return;
	}
	this->history = history;
}
float Student::getAverage() {
	return (this->mathematics + this->english + this->history) / 3;
}