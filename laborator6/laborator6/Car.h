#pragma once
#include <iostream>
#include "Weather.h"

class Car {
public:
	Car() {
		printf("Car Constructor lmao.\n");
	}
	Car(const Car& toCopy) {
		printf("Car Copied by Constructor.\n");
	}
	Car(Car&& toMove) {
		printf("Car Moved by Constructor.\n");
	}
	virtual ~Car() {
		printf("Car Destructor lmao.\n");
	}
	virtual const char* GetName() = 0;
	double virtual GetFuelCapacity() = 0;			//in L
	double virtual GetFuelConsumption() = 0;		//in L/km
	double virtual GetAverageSpeed(Weather) = 0;	//in kh/h
	//useless?
	Car& operator= (const Car& toCopy) {
		printf("Car Copied by Assignment.\n");
		if (this != &toCopy) {

		}
		return *this;
	}
	//even more so
	Car& operator= (Car&& toMove) noexcept {
		printf("Car Moved by Assignment.\n");
		if (this != &toMove) {

		}
		return *this;
	}
};