#include <iostream>
#include "Circuit.h"

Circuit::Circuit() : Circuit(DEFAULT_WEATHER, DEFAULT_LENGTH) {

}
Circuit::Circuit(const Weather weather) : Circuit(weather, DEFAULT_LENGTH) {

}
Circuit::Circuit(const double length) : Circuit(DEFAULT_WEATHER, length) {

}
Circuit::Circuit(const Weather weather, const double length) {
	this->cars = new Car*[0];
	if (this->cars == nullptr) {
		printf("OOPSIE, can't allocate enough heap memory.\n");
	}
	this->weather = weather;
	this->length = length;
	this->numberOfCars = 0;
}
Circuit::Circuit(Car* firstCar) : Circuit(firstCar, DEFAULT_WEATHER, DEFAULT_LENGTH) {

}
Circuit::Circuit(Car* firstCar, const Weather weather) : Circuit(firstCar, weather, DEFAULT_LENGTH) {

}
Circuit::Circuit(Car* firstCar, const double length) : Circuit(firstCar, DEFAULT_WEATHER, length) {

}
Circuit::Circuit(Car* firstCar, const Weather weather, const double length) {
	this->cars = new Car*[1];
	if (this->cars == nullptr) {
		printf("OOPSIE, can't allocate enough heap memory.\n");
	}
	this->cars[0] = firstCar;	//idk how but it would be nice if i could call a copy constructor here
								//giving out references to heap allocated class instances makes it so if the user deletes
								//a car added with addCar() the car vector will have an invalid car
								//I've confirmed this theory like 5 seconds ago so that stuff above this is a valid concern
	this->weather = weather;
	this->length = length;
	this->numberOfCars = 1;
}
Circuit::~Circuit() {
	delete[] this->cars;
	this->cars = nullptr;
	this->weather = DEFAULT_WEATHER;
	this->length = 0;
	this->numberOfCars;
}

double Circuit::GetLength() {
	return this->length;
}
void Circuit::SetLength(double length) {
	this->length = length;
}
Weather Circuit::GetWeather() {
	return this->weather;
}
void Circuit::SetWeather(Weather weather) {
	this->weather = weather;
}
void Circuit::AddCar(Car* car) {
	Car** aux = new Car*[this->numberOfCars + 1];
	if (aux == nullptr) {
		printf("OOPSIE, can't allocate enough heap memory.\n");
		exit(1);
	}
	for (uint64_t i = 0; i < this->numberOfCars; ++i) {
		aux[i] = this->cars[i];
	}
	aux[this->numberOfCars] = car;	//same idea as on line 36
	delete[] this->cars;
	this->cars = aux;
	aux = nullptr;
	++numberOfCars;
}
void Circuit::RemoveCar() {
	Car** aux = new Car*[this->numberOfCars - 1];
	if (aux == nullptr) {
		printf("OOPSIE, can't allocate enough heap memory.\n");
	}
	for (uint64_t i = 0; i < this->numberOfCars - 1; ++i) {
		aux[i] = this->cars[i];
	}
	delete[] this->cars;
	this->cars = aux;
	aux = nullptr;
	--numberOfCars;
}
void Circuit::Race() {
	double i_Dist, j_Dist;
	Car* aux;
	for (uint64_t i = 0; i < this->numberOfCars - 1; ++i) {
		for (uint64_t j = i + 1; j < this->numberOfCars; ++j) {
			i_Dist = this->cars[i]->GetFuelCapacity() / this->cars[i]->GetFuelConsumption();
			j_Dist = this->cars[j]->GetFuelCapacity() / this->cars[j]->GetFuelConsumption();
			if (i_Dist >= this->length && j_Dist >= this->length) {
				if (this->cars[i]->GetAverageSpeed(this->weather) < this->cars[j]->GetAverageSpeed(this->weather)) {
					aux = this->cars[i];
					this->cars[i] = this->cars[j];
					this->cars[j] = aux;
				}
			}
			else if (i_Dist >= this->length && j_Dist < this->length) {

			}
			else if (i_Dist < this->length && j_Dist >= this->length) {
				aux = this->cars[i];
				this->cars[i] = this->cars[j];
				this->cars[j] = aux;
			}
			else {
				//optional
				/*
				if (this->cars[i]->GetAverageSpeed(this->weather) < this->cars[j]->GetAverageSpeed(this->weather)) {
					aux = this->cars[i];
					this->cars[i] = this->cars[j];
					this->cars[j] = aux;
				}
				/**/
				//could also sort by distance travelled
				if (i_Dist < j_Dist) {
					aux = this->cars[i];
					this->cars[i] = this->cars[j];
					this->cars[j] = aux;
				}
			}
		}
	}
}
void Circuit::ShowFinalRanks() {
	uint64_t i_Time;
	for (uint64_t i = 0; i < this->numberOfCars && this->cars[i]->GetFuelCapacity() / this->cars[i]->GetFuelConsumption() >= this->length; ++i) {
		printf("Name: %s\n", this->cars[i]->GetName());
		printf("Average Speed: %f\n", this->cars[i]->GetAverageSpeed(this->weather));
		i_Time = this->length * 3600 / this->cars[i]->GetAverageSpeed(this->weather);
		printf("Time: %llu hours %llu minutes and %llu seconds.\n\n", i_Time / 3600, i_Time % 3600 / 60, i_Time % 60);
	}
}
void Circuit::ShowWhoDidNotFinish() {
	uint64_t i = 0;
	while (i < this->numberOfCars && this->cars[i]->GetFuelCapacity() / this->cars[i]->GetFuelConsumption() >= this->length) {
		++i;
	}
	while (i < this->numberOfCars) {
		printf("Name: %s\n", this->cars[i]->GetName());
		printf("Maximum Distance travelled: %f\n",
			this->cars[i]->GetFuelCapacity() / this->cars[i]->GetFuelConsumption());
		printf("Average Speed: %f\n\n", this->cars[i]->GetAverageSpeed(this->weather));
		++i;
	}
}