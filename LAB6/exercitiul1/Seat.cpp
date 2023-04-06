#include "Seat.h"

void Seat::SetfuelCapacity(double val) { fuelCapacity = val; }
void Seat::SetfuelConsumption(double val) { fuelConsumption = val; }
void Seat::SetSpeed(double val, Weather weather)
{
	if (weather == Rain) rainSpeed = val;
	else if (weather == Sunny) sunnySpeed = val;
	else if (weather == Snow) snowSpeed = val;
}

double Seat::GetfuelCapacity() { return fuelCapacity; }
double Seat::GetfuelConsumption() { return fuelConsumption; }
double Seat::GetSpeed(Weather weather)
{
	if (weather == Rain) return rainSpeed;
	else if (weather == Sunny) return sunnySpeed;
	else if (weather == Snow) return snowSpeed;
}

void Seat::SetcarModel(const char* s)
{
	strcpy(carModel, s);
}
const char* Seat::GetcarModel()
{
	return carModel;
}