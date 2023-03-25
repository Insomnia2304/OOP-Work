#pragma once
class Number
{
	// add data members
	char* v;
	int len, base;

public:

	Number(int base, int n); //will create a zeroed n-len number
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(int value);
	Number();

	Number(const Number& x);
	Number(Number&& x);

	void Zero(int newLen); //will fill with zeroes till newLen
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base

	friend Number operator+(Number a, Number b);
	friend Number operator-(Number a, Number b);
	void operator+=(Number a);
	void operator-=(Number a);
	Number& operator=(const char* value);
	Number& operator=(const Number& a);
	Number& operator=(int value);
	char operator[](int x);
	void operator--();
	void operator--(int x);

	bool operator<(Number a);
	bool operator>(Number a);
	bool operator<=(Number a);
	bool operator>=(Number a);
	bool operator==(Number a);
};