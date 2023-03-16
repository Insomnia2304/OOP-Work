#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList a;
	a.Init();
	a.Add(6);
	a.Add(1);
	a.Add(-4);
	a.Add(3);
	a.Add(2);
	a.Print();
	a.Sort();
	a.Print();

	return 0;
}