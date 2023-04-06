#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "Weather.h"
using namespace std;

class Car
{
protected:
	double fuelCapacity; //liters
	double fuelConsumption; //liters/100km
	double rainSpeed, sunnySpeed, snowSpeed; //km/h
	char carModel[50];
public:
	virtual void SetfuelCapacity(double val) = 0;
	virtual void SetfuelConsumption(double val) = 0;
	virtual void SetSpeed(double val, Weather weather) = 0;
	virtual void SetcarModel(const char* s) = 0;
	virtual double GetfuelCapacity() = 0;
	virtual double GetfuelConsumption() = 0;
	virtual double GetSpeed(Weather weather) = 0;
	virtual const char* GetcarModel() = 0;
};