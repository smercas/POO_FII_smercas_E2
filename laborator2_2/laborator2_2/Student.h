#pragma once
class Student {
	const char* name;
	float mathematics, english, history;
public:
	Student();
	const char* getName();
	void setName(const char* name);
	float getMathematicsGrade();
	void setMathematicsGrade(float mathematics);
	float getEnglishGrade();
	void setEnglishGrade(float english);
	float getHistoryGrade();
	void setHistoryGrade(float history);
	float getAverage();
};