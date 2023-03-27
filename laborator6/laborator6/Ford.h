#pragma once
#include "Car.h"

class Ford : public Car {
public:
	Ford() {
		printf("Ford Constructor.\n");
	}
	virtual ~Ford() override final {
		printf("Ford Destructor.\n");
	}
	virtual const char* GetName() override final;
	double virtual GetFuelCapacity() override final;
	double virtual GetFuelConsumption() override final;
	double virtual GetAverageSpeed(Weather) override final;
};