#include "BMW.h"

void BMW::SetfuelCapacity(double val) { fuelCapacity = val; }
void BMW::SetfuelConsumption(double val) { fuelConsumption = val; }
void BMW::SetSpeed(double val, Weather weather)
{
	if (weather == Rain) rainSpeed = val;
	else if (weather == Sunny) sunnySpeed = val;
	else if (weather == Snow) snowSpeed = val;
}

double BMW::GetfuelCapacity() { return fuelCapacity; }
double BMW::GetfuelConsumption() { return fuelConsumption; }
double BMW::GetSpeed(Weather weather)
{
	if (weather == Rain) return rainSpeed;
	else if (weather == Sunny) return sunnySpeed;
	else if (weather == Snow) return snowSpeed;
}

void BMW::SetcarModel(const char* s)
{
	strcpy(carModel, s);
}
const char* BMW::GetcarModel()
{
	return carModel;
}