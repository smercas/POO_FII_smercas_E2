#include <iostream>
#include "Circuit.h"

int main()
{
	Circuit c;
	Car* dacia = new Dacia();
	Car* toyota = new Toyota();
	Car* mercedes = new Mercedes();
	Car* ford = new Ford();
	Car* mazda = new Mazda();
	c.SetLength(1000);
	c.SetWeather(Weather::Rain);
	c.AddCar(dacia);
	c.AddCar(toyota);
	c.AddCar(mercedes);
	c.AddCar(ford);
	c.AddCar(mazda);
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	delete dacia;
	delete toyota;
	delete mercedes;
	delete ford;
	delete mazda;
	return 0;
}