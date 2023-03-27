#pragma once
#include <cstdint>
#include "Car.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"
#define DEFAULT_LENGTH 100
#define DEFAULT_WEATHER Weather::Sunny

class Circuit {
	Car** cars;
	double length;
	Weather weather;
	uint64_t numberOfCars;
public:
	Circuit();
	Circuit(const Weather);
	Circuit(const double);
	Circuit(const Weather, const double);
	Circuit(Car*);
	Circuit(Car*, const Weather);
	Circuit(Car*, const double);
	Circuit(Car*, const Weather, const double);
	~Circuit();
	double GetLength();
	void SetLength(double);
	Weather GetWeather();
	void SetWeather(Weather);
	void AddCar(Car*);
	void RemoveCar();
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};