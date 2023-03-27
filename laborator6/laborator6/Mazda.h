#pragma once
#include "Car.h"

class Mazda : public Car {
public:
	Mazda() {
		printf("Mazda Constructor.\n");
	}
	virtual ~Mazda() override final {
		printf("Mazda Destructor.\n");
	}
	virtual const char* GetName() override final;
	double virtual GetFuelCapacity() override final;
	double virtual GetFuelConsumption() override final;
	double virtual GetAverageSpeed(Weather) override final;
};