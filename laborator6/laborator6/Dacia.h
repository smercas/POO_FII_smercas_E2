#pragma once
#include "Car.h"

class Dacia : public Car{
public:
	Dacia() {
		printf("Dacia Constructor.\n");
	}
	virtual ~Dacia() override final {
		printf("Dacia Destructor.\n");
	}
	virtual const char* GetName() override final;
	double virtual GetFuelCapacity() override final;
	double virtual GetFuelConsumption() override final;
	double virtual GetAverageSpeed(Weather) override final;
};