#pragma once
#include "Car.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"

class Circuit
{
	int carsIndex;
	double length; //km
	Weather weather;
	Car** cars;
	double* time;
public:
	Circuit();
	~Circuit();
	void SetLength(double length);
	void SetWeather(Weather weather);
	bool AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

