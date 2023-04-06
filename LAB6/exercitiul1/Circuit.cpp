#include "Circuit.h"

Circuit::Circuit()
{
	carsIndex = 0;
	length = 0;
	weather = Sunny;
	cars = new Car * [30]; //default value, ca sa nu realoc de fiecare data
	time = new double[30];
}

Circuit::~Circuit()
{
    for (int i = 0; i < carsIndex; i++)
	 delete cars[i];
	delete[] cars;
    delete[] time;
}

void Circuit::SetLength(double length)
{
	this->length = length;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

bool Circuit::AddCar(Car* car)
{
	if (carsIndex == 30) return 0;
	cars[carsIndex++] = car;
	return 1;
}

void Circuit::Race()
{
	int i;
	cars[0]->SetSpeed(100, Sunny);
	cars[1]->SetSpeed(50, Sunny);
	cars[2]->SetSpeed(25, Sunny);
	cars[3]->SetSpeed(200, Sunny);
	cars[4]->SetSpeed(400, Sunny);
	cars[0]->SetcarModel("Volvo XC60");
	cars[1]->SetcarModel("BMW i7");
	cars[2]->SetcarModel("Seat Ibiza");
	cars[3]->SetcarModel("Fiat Panda");
	cars[4]->SetcarModel("Land RangeRover");
	for (i = 0; i < carsIndex; i++)
	{ //initializarile
		cars[i]->SetfuelCapacity(50 * i);
		cars[i]->SetfuelConsumption(5 + i);
		cars[i]->SetSpeed(cars[i]->GetSpeed(Sunny) / 2, Rain);
		cars[i]->SetSpeed(cars[i]->GetSpeed(Sunny) / 4, Snow);
	}
	cars[0]->SetfuelCapacity(3); //ca sa pot trata toate cazurile,
	cars[1]->SetfuelCapacity(4); //chiar daca e putin impractic
	for (i = 0; i < carsIndex; i++)
	{ 
		if (cars[i]->GetfuelCapacity() < length / 100 * cars[i]->GetfuelConsumption())
			time[i] = -1; ///nu termina
		else if (cars[i]->GetSpeed(weather) > 0) //pentru a se putea face impartirea
			time[i] = length / cars[i]->GetSpeed(weather);
	}
}

void Circuit::ShowFinalRanks()
{
	int i, j;
	bool ok = 1;
	double temp;
	Car* temp2;
	while (ok)
	{
		ok = 0;
		for (i = 1; i < carsIndex; i++)
			if (time[i] < time[i - 1])
			{
				ok = 1;
				temp = time[i];
				time[i] = time[i - 1];
				time[i - 1] = temp;
				temp2 = cars[i];
				cars[i] = cars[i - 1];
				cars[i - 1] = temp2;
			}
	}
	for (i = 0; time[i] == -1; i++);
	for (j = 1; i < carsIndex; j++, i++)
	{
		if (i && time[i] == time[i - 1]) j--;
		cout << "Masina " << cars[i]->GetcarModel() << " a terminat cursa in " << time[i] << " ore, pe locul " << j << "!\n";
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	int i;
	for (i = 0; i < carsIndex; i++)
		if (time[i] == -1)
			cout << "Masina " << cars[i]->GetcarModel() << " nu a reusit sa termine cursa. :(" << '\n';
}
