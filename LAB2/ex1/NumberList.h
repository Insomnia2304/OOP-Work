#pragma once
#include <iostream>
using namespace std;

class NumberList
{
	int numbers[10];
	int count;

public:
	void Init();
	bool Add(int x);

	void Sort();
	void Print();
};

