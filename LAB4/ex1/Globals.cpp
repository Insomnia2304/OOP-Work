#include "Globals.h"
#include <algorithm>
using namespace std;

int stoi(char* p, int n)
{
	int val = 0;
	for (int i = 0; i < n; i++)
		val = val * 10 + p[i] - '0';
	return val;
}

int part(int* v, int left, int right, bool ascendent)
{///pune pivotul pe pozitia corecta pentru functia Sort::QuickSort
	int pivot = v[right];
	int i = (left - 1), j;

	for (j = left; j < right; j++)
		if (v[j] > pivot && !ascendent || v[j] < pivot && ascendent)
		{
			i++;
			swap(v[i], v[j]);
		}
	swap(v[i + 1], v[right]);
	return (i + 1);
}