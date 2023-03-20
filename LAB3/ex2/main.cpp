#include "Canvas.h"
#include <iostream>
using namespace std;

char **c;

int main()
{
	Canvas a(10,10);

	cout << "Se va afisa canvas-ul gol:\n";
	a.Print();

	a.FillRect(1, 0, 8, 9, 'x');
	a.Print();
	a.Clear();

	a.DrawRect(2, 5, 8, 8, 'x');
	a.Print();
	a.SetPoint(0, 0, 'a');
	a.SetPoint(9, 9, 'z');
	a.Print();
	a.Clear();

	a.DrawLine(0, 0, 9, 9, '*');
	a.Print();
	a.Clear();

	a.DrawLine(2, 2, 9, 5, '*'); //(abscisa, ordonata)
	a.Print();
	a.Clear();

	cout << "Se va afisa un cerc cu raza 0:\n";
	a.FillCircle(5, 5, 0, '*');
	a.Print();
	a.Clear();

	cout << "Se va afisa un cerc cu raza 4:\n";
	a.FillCircle(5, 5, 4, '*');
	a.Print();
	a.Clear();

	cout << "Se va afisa conturul unui cerc cu raza 4:\n";
	a.DrawCircle(5, 5, 4, '*');
	a.Print();
	a.Clear();
	return 0;
}