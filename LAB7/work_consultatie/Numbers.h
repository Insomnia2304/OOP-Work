#include <iostream>
#include <algorithm>
using namespace std;
#pragma once
class Numbers
{
	unsigned char p[64];
	short int nr;

	int getLen(const char*);
public:
	Numbers();
	Numbers(const char*);
	Numbers(const Numbers& x);
	~Numbers();
	operator short();
	friend ostream& operator<< (ostream&, const Numbers& x);
	Numbers operator+(const Numbers& a);
	int operator[](int index);

	int min();
	int max();
};

