#pragma once
#include <iostream>
#include "Weather.h"

class Car {
public:
	Car() {
		printf("Car Constructor lmao.\n");
	}
	virtual ~Car() {
		printf("Car Destructor lmao.\n");
	}
	virtual const char* GetName() = 0;
	double virtual GetFuelCapacity() = 0;			//in L
	double virtual GetFuelConsumption() = 0;		//in L/km
	double virtual GetAverageSpeed(Weather) = 0;	//in kh/h
};