#include <iostream>
#include "NumberList.h"

bool countErrorMessage(int x) {
	if (x < 0 || x > 10) {
		printf("Error, undefined behaviour: count is either negative or greater than the maximum array length. The class instance might not have been initialised yet\n");
		return true;
	}
	return false;
}

void NumberList::Init() {
	this->count = 0;
} //Shouldn't this be a constructor?

bool NumberList::Add(int x) {
	if (!countErrorMessage(this->count)) {
		if (this->count >= 10) return false;
		this->numbers[this->count] = x;
		this->count++;
		return true;
	}
	return false;
}

void NumberList::Sort() {
	if (!countErrorMessage(this->count)) {
		for (int i = 0; i < this->count - 1; i++) {
			for (int j = i + 1; j <= this->count - 1; j++) {
				if (this->numbers[i] > this->numbers[j]) {
					this->numbers[i] = this->numbers[i] + this->numbers[j];
					this->numbers[j] = this->numbers[i] - this->numbers[j];
					this->numbers[i] = this->numbers[i] - this->numbers[j];
				}
			}
		}
	}
}

void NumberList::Print() {
	int a = 0;
	if (!countErrorMessage(this->count)) {
		if (this->count == 0) {
			//printf("The \"%s\" class instance is empty.", vName(this));
			//it prints "this" but i want it to print "nl" or whatever the class instance's name is

			printf("The printed class instance is empty");
		}
		else {
			printf("%d", this->numbers[0]);
			for (int i = 1; i < this->count; i++) {
				printf(", %d", this->numbers[i]);
			}
		}
		printf("\n");
	}
}