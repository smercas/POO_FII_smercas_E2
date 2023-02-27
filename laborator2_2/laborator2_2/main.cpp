#include <iostream>
#include "Student.h";
#include "global_functions.h"

using namespace std;

void main() {
	Student me, you;
	me.setName("Mercas Stefan-Alexandru");
	me.setMathematicsGrade(8);
	me.setEnglishGrade(0.9);
	me.setHistoryGrade(1);
	you.setName("????");
	you.setMathematicsGrade(10.1);
	you.setEnglishGrade(9.9);
	you.setHistoryGrade(-100);
	printf("Name: %s\nAverage: %f\n", me.getName(), me.getAverage());
	printf("Name: %s\nAverage: %f\n", you.getName(), you.getAverage());
	printf("%d, %d, %d, %d, %d\n", cmpName(me, you), cmpMathematics(me, you), cmpEnglish(me, you), cmpHistory(me, you), cmpAverage(me, you));
}