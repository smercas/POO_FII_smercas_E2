#pragma once
#include "Car.h"

class Mercedes : public Car {
public:
	Mercedes() {
		printf("Mercedes Constructor.\n");
	}
	virtual ~Mercedes() override final {
		printf("Mercedes Destructor.\n");
	}
	virtual const char* GetName() override final;
	double virtual GetFuelCapacity() override final;
	double virtual GetFuelConsumption() override final;
	double virtual GetAverageSpeed(Weather) override final;
};