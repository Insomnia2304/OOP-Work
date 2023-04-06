#include "Volvo.h"

void Volvo::SetfuelCapacity(double val) { fuelCapacity = val; }
void Volvo::SetfuelConsumption(double val) { fuelConsumption = val; }
void Volvo::SetSpeed(double val, Weather weather)
{
	if (weather == Rain) rainSpeed = val;
	else if (weather == Sunny) sunnySpeed = val;
	else if (weather == Snow) snowSpeed = val;
}

double Volvo::GetfuelCapacity() { return fuelCapacity; }
double Volvo::GetfuelConsumption() { return fuelConsumption; }
double Volvo::GetSpeed(Weather weather)
{
	if (weather == Rain) return rainSpeed;
	else if (weather == Sunny) return sunnySpeed;
	else if (weather == Snow) return snowSpeed;
}

void Volvo::SetcarModel(const char* s)
{
	strcpy(carModel, s);
}
const char* Volvo::GetcarModel()
{
	return carModel;
}