#include "Fiat.h"

void Fiat::SetfuelCapacity(double val) { fuelCapacity = val; }
void Fiat::SetfuelConsumption(double val) { fuelConsumption = val; }
void Fiat::SetSpeed(double val, Weather weather)
{
	if (weather == Rain) rainSpeed = val;
	else if (weather == Sunny) sunnySpeed = val;
	else if (weather == Snow) snowSpeed = val;
}

double Fiat::GetfuelCapacity() { return fuelCapacity; }
double Fiat::GetfuelConsumption() { return fuelConsumption; }
double Fiat::GetSpeed(Weather weather)
{
	if (weather == Rain) return rainSpeed;
	else if (weather == Sunny) return sunnySpeed;
	else if (weather == Snow) return snowSpeed;
}

void Fiat::SetcarModel(const char* s)
{
	strcpy(carModel, s);
}
const char* Fiat::GetcarModel()
{
	return carModel;
}