#include "RangeRover.h"

void RangeRover::SetfuelCapacity(double val) { fuelCapacity = val; }
void RangeRover::SetfuelConsumption(double val) { fuelConsumption = val; }
void RangeRover::SetSpeed(double val, Weather weather)
{
	if (weather == Rain) rainSpeed = val;
	else if (weather == Sunny) sunnySpeed = val;
	else if (weather == Snow) snowSpeed = val;
}

double RangeRover::GetfuelCapacity() { return fuelCapacity; }
double RangeRover::GetfuelConsumption() { return fuelConsumption; }
double RangeRover::GetSpeed(Weather weather)
{
	if (weather == Rain) return rainSpeed;
	else if (weather == Sunny) return sunnySpeed;
	else if (weather == Snow) return snowSpeed;
}

void RangeRover::SetcarModel(const char* s)
{
	strcpy(carModel, s);
}
const char* RangeRover::GetcarModel()
{
	return carModel;
}