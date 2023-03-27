#pragma once
#include "Car.h"

class Toyota : public Car {
public:
	Toyota() {
		printf("Toyota Constructor.\n");
	}
	virtual ~Toyota() override final {
		printf("Toyota Destructor.\n");
	}
	virtual const char* GetName() override final;
	double virtual GetFuelCapacity() override final;
	double virtual GetFuelConsumption() override final;
	double virtual GetAverageSpeed(Weather) override final;
};