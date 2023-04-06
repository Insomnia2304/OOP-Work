#pragma once
#include "Car.h"
class Fiat : public Car
{
public:
	void SetfuelCapacity(double val);
	void SetfuelConsumption(double val);
	void SetSpeed(double val, Weather weather);
	double GetfuelCapacity();
	double GetfuelConsumption();
	double GetSpeed(Weather weather);
	void SetcarModel(const char* s);
	const char* GetcarModel();
};