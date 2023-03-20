#include "Sort.h"
#include <iostream>
using namespace std;

int main()
{
	Sort a(10, 0, 1000);
	a.Print();
	
	int* arr = new int[5] {1, 2, 3, 4, 5};
	Sort b(5, arr);
	b.Print();

	Sort c(6, 99, 5, 4, 3, 2, 1);
	c.Print();

	char s[] = "15,17,200,0,1,7";
	Sort d(s);
	d.Print();

	Sort e;
	e.Print();
	cout << "Vectorul are: " << e.GetElementsCount() << " elemente. Elementul de pe pozitia 0 este : " << e.GetElementFromIndex(0) << ".";
	cout << "\n\n------------------------------\n\n";

	e.InsertSort(0);
	e.Print();

	e.BubbleSort(1);
	e.Print();

	d.QuickSort(0, d.GetElementsCount() - 1, 1);
	d.Print();
	return 0;
}