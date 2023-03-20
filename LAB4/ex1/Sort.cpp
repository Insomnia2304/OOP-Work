#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include "globals.h"
#include <stdlib.h>  
#include <time.h> 
#include <iostream>
#include <stdarg.h>
#include <cstring>
using namespace std;

void Sort::Print()
{
	cout << "Numarul curent de elemente este: " << numberOfElements << '\n';
	for (int i = 0; i < numberOfElements; i++)
		cout << v[i] << ' ';
	cout << "\n\n------------------------------\n\n";
}

Sort::Sort(int numberOfElements, int minElement, int maxElement)
{
	this->numberOfElements = numberOfElements;
	v = new int[numberOfElements];

	srand(time(NULL));
	for (int i = 0; i < numberOfElements; i++)
	{
		v[i] = minElement + rand() % (maxElement - minElement + 1);
	}
}

Sort::Sort(int numberOfElements, int* v)
{
	this->numberOfElements = numberOfElements;
	this->v = new int[numberOfElements];
	memcpy(this->v, v, numberOfElements * sizeof(int));
}

Sort::Sort(int numberOfElements, ...)
{
	this->numberOfElements = numberOfElements;
	this->v = new int[numberOfElements];
	va_list vl;
	va_start(vl, numberOfElements);
	for (int i = 0; i < numberOfElements; i++)
		v[i] = va_arg(vl, int);
	va_end(vl);
}

Sort::Sort(char* c)
{
	int i, total = 0;
	char *p = new char[strlen(c) + 1];
	char *copy = p;
	strcpy(p, c);

	///alfu mai intai cate numere voi avea, ca sa stiu cat aloc
	p = strtok(p, ",");
	while (p)
	{
		total++;
		p = strtok(NULL, ",");
	}

	///acum aloc
	p = copy;
	strcpy(p, c);
	p = strtok(p, ",");
	v = new int[total];

	while (p)
	{
		for (i = 0; p[i] != ',' && p[i]; i++);
		v[numberOfElements++] = stoi(p, i);
		p = strtok(NULL, ",");
	}
	delete copy;
}

Sort::Sort() : numberOfElements(5), v(new int[5] {8, 5, 2, 14, 11})
{

}

Sort::~Sort()
{
	delete v;
}

void Sort::InsertSort(bool ascendent)
{
	int i, j, temp;
	for (i = 1; i < numberOfElements; i++)
	{
		temp = v[i];
		for (j = i - 1; j >= 0 && (ascendent && v[j] > temp || !ascendent && v[j] < temp); j--)
		{
			v[j + 1] = v[j];
		}
		if (v[j + 1] != temp)
			v[j + 1] = temp;
	}

}

void Sort::QuickSort(int left, int right, bool ascendent)
{
	int pivot = 0;
	if (left < right)
	{
		pivot = part(v, left, right, ascendent);
		QuickSort(left, pivot - 1, ascendent);
		QuickSort(pivot + 1, right, ascendent);
	}
}


void Sort::BubbleSort(bool ascendent)
{
	int i;
	bool ok = 1;
	while (ok)
	{
		ok = 0;
		for (i = 1; i < numberOfElements; i++)
			if (ascendent && v[i] < v[i - 1] || !ascendent && v[i] > v[i - 1])
			{
				swap(v[i], v[i - 1]);
				ok = 1;
		    }

	}
}

int  Sort::GetElementsCount()
{
	return numberOfElements;
}

int  Sort::GetElementFromIndex(int index)
{
	return v[index];
}
