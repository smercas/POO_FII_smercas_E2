#include <iostream>
#include "Student.h"
#include "global_functions.h"

int cmpName(Student A, Student B) {
	if (strcmp(A.getName(), B.getName()) < 0) return -1;
	else if (strcmp(A.getName(), B.getName()) > 0) return 1;
	else return 0;
}
int cmpMathematics(Student A, Student B) {
	if (A.getMathematicsGrade() < B.getMathematicsGrade()) return -1;
	else if (A.getMathematicsGrade() > B.getMathematicsGrade()) return 1;
	else return 0;
}
int cmpEnglish(Student A, Student B) {
	if (A.getEnglishGrade() < B.getEnglishGrade()) return -1;
	else if (A.getEnglishGrade() > B.getEnglishGrade()) return 1;
	else return 0;
}
int cmpHistory(Student A, Student B) {
	if (A.getHistoryGrade() < B.getHistoryGrade()) return -1;
	else if (A.getHistoryGrade() > B.getHistoryGrade()) return 1;
	else return 0;
}
int cmpAverage(Student A, Student B) {
	if (A.getAverage() < B.getAverage()) return -1;
	else if (A.getAverage() > B.getAverage()) return 1;
	else return 0;
}