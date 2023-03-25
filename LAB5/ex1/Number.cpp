#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Number.h"
using namespace std;

Number::Number(int base, int n)
{
	this->base = base;
	this->len = n;
	v = new char[n + 1];
	for (int i = 0; i < n; i++)
		 v[i] = '0';
	v[n] = 0;
}

Number::Number(const char* value, int base) // where base is between 2 and 16
{
	int i, j, len;
	len = strlen(value);
	this->base = base;
	this->len = len;
	v = new char[this->len + 1];
	for (i = 0, j = len - 1; i < len; i++, j--)
		v[i] = value[j];
	v[len] = 0;
}

Number::Number(int value)
{
	base = 10;
	char* temp = new char[100];
	int lgtemp = 0;
	while (value) { temp[lgtemp++] = '0' + value % 10; value /= 10; }
	temp[lgtemp] = 0;
	v = new char[lgtemp + 1];
	strcpy(v, temp);
	delete[] temp;
	len = lgtemp;
}

Number::Number()
{
	base = 10;
	len = 1;
	v = new char[2] { '0', 0 };
}

Number::~Number()
{
	delete[] v;
}

Number::Number(const Number& x)
{
	this->len = x.len;
	this->base = x.base;
	this->v = new char[x.len + 1];
	strcpy(this->v, x.v);
}

Number::Number(Number&& x)
{
	this->len = x.len;
	this->base = x.base;
	this->v = x.v;
	x.v = nullptr;
}

void Number::Zero(int newLen)
{
	char* temp = new char[newLen + 1];
	strcpy(temp, v);
	int i;
	for (i = len; i < newLen; i++)
	   	temp[i] = '0';
	temp[i] = 0;
	len = newLen;
	delete[] v;
	v = temp;
}

void Number::Print()
{
	for (int i = len - 1; i >= 0; i--)
		cout << v[i];
	cout << '\n';
}

void Number::SwitchBase(int newBase)
{
	
	int i;
	long long int val = 0, pow = 1;
	for (i = 0; i < len; i++)
	{
		if (v[i] >= 'A')
			val += (10 + v[i] - 'A') * pow;
		else val += (v[i] - '0') * pow;
		pow *= base;
	}
	//cout << val << '\n';
	
	i = 0;
	char* new_v = new char[len * 5];
	if (!val) { new_v[i++] = '0';}
	while (val) 
	{	if (val % newBase >= 10)
		    new_v[i++] = val % newBase - 10 + 'A';
	    else 
		    new_v[i++] = val % newBase + '0';
		val /= newBase; 
	}
	new_v[i] = 0;
	char* temp_v = new char[i + 1];
	strcpy(temp_v, new_v);
	delete[] v;
	delete[] new_v;
	v = temp_v;
	base = newBase;
	len = i;
	
}

int Number::GetDigitsCount() // returns the number of digits for the current number
{
	return len;
}

int Number::GetBase() // returns the current base
{
	return base;
}

Number operator+(Number a, Number b)
{
	int baseMax = max(a.base, b.base);
    a.SwitchBase(10);
	b.SwitchBase(10);
	if (a.len < b.len) a.Zero(b.len);
	else if (a.len > b.len) b.Zero(a.len);
	
	Number c(10, a.len + 1); ///se poate depasi cu o cifra, de asta +1

	int i, carry = 0, val;
	for (i = 0; i < a.len; i++)
	{
		val = a.v[i] - '0' + b.v[i] - '0' + carry;
		c.v[i] = '0' + val % 10;
		carry = val / 10;
	}
	if (carry) c.v[i] = '1';
	else
	{//dealoc acel spatiu extra
		c.v[i] = 0;
		char* temp = new char[c.len];
		strcpy(temp, c.v);
		delete[] c.v;
		c.v = temp;
		c.len--;
	} 
	c.SwitchBase(baseMax);
	return c;
}

Number operator-(Number a, Number b)
{///c = a - b, a >= b
	int baseMax = max(a.base, b.base);
	a.SwitchBase(10);
	b.SwitchBase(10);
	if (a.len < b.len) a.Zero(b.len);
	else if (a.len > b.len) b.Zero(a.len);

	Number c(10, a.len);

	int i, carry = 0, val;
	for (i = 0; i < a.len; i++)
	{
		val = a.v[i] - '0' - (b.v[i] - '0') + carry;
		if (val < 0) { c.v[i] ='0' + val + 10; carry = -1; }
		else { c.v[i] = '0' + val; carry = 0; }
	}
	//dealoc spatiul extra (oricat ar fi)
	while (c.v[c.len - 1] == 0 && c.len > 1) c.len--;
	if (c.len < a.len) //am spatiu alocat nefolosit, realoc
	{
		char* temp = new char[c.len + 1];
		strcpy(temp, c.v);
		delete[] c.v;
		c.v = temp;
	}
	c.SwitchBase(baseMax);
	return c;
}

Number& Number::operator=(const char* value)
{
	delete[] v;
	len = strlen(value);
	base = 10;
	v = new char[len + 1];
	int i, j;
	for (i = 0, j = len - 1; i < len; i++, j--)
		 v[i] = value[j];
	v[len] = 0;
	return (*this);
}

Number& Number::operator=(const Number& a)
{
	delete[] v;
	len = a.len;
	base = a.base;
	v = new char[a.len + 1];
	strcpy(v, a.v);
	return (*this);
}

Number& Number::operator=(int value)
{//isi pastreaza baza initiala
	char* temp = new char[100];
	int lgtemp = 0;
	while (value)
	{
		if (value % base >= 10)
			temp[lgtemp++] = value % base - 10 + 'A';
		else
			temp[lgtemp++] = value % base + '0';
		value /= base;
	}
	temp[lgtemp] = 0;
	delete[] v;
	v = new char[lgtemp + 1];
	strcpy(v, temp);
	delete[] temp;
	len = lgtemp;
	return (*this);
}

char Number::operator[](int x)
{
	return this->v[len-(x + 1)]; //pentru ca sunt reversed
}

void Number::operator--()
{
	if (len == 1)
	{
		v[0] = '0';
		return;
	}
	v[len - 1] = 0; len--;
	while (v[len - 1] == 0 && len > 1) len--;
	//acum realoc
	char* temp = new char[len + 1];
	strcpy(temp, v);
	delete[] v;
	v = temp;
}

void Number::operator--(int x)
{
	if (len == 1)
	{
		v[0] = '0';
		return;
	}
	len--;
	char* temp = new char[len + 1];
	strcpy(temp, v + 1);
	delete[] v;
	v = temp;
}

bool Number::operator<(Number a)
{
	int base1 = base;
	int base2 = a.base;
	a.SwitchBase(10);
	this->SwitchBase(10);
	if (len < a.len) { this->SwitchBase(base1); a.SwitchBase(base2); return 1; }
	if (len > a.len) { this->SwitchBase(base1); a.SwitchBase(base2); return 0; }
	for (int i = len - 1; i >= 0; i--)
		if (v[i] < a.v[i]) { this->SwitchBase(base1); a.SwitchBase(base2); return 1; }
		else if (v[i] > a.v[i]) { this->SwitchBase(base1); a.SwitchBase(base2); return 0; }
	this->SwitchBase(base1); a.SwitchBase(base2); return 0;
}

bool Number::operator>(Number a)
{
	int base1 = base;
	int base2 = a.base;
	a.SwitchBase(10);
	this->SwitchBase(10);
	if (len > a.len) { this->SwitchBase(base1); a.SwitchBase(base2); return 1; }
	if (len < a.len) { this->SwitchBase(base1); a.SwitchBase(base2); return 0; }
	for (int i = len - 1; i >= 0; i--)
		if (v[i] < a.v[i]) { this->SwitchBase(base1); a.SwitchBase(base2); return 0; }
		else if (v[i] > a.v[i]) { this->SwitchBase(base1); a.SwitchBase(base2); return 1; }
	this->SwitchBase(base1); a.SwitchBase(base2); return 0;
}

bool Number::operator<=(Number a)
{
	return !(*this > a);
}

bool Number::operator>=(Number a)
{
	return !(*this < a);
}

bool Number::operator==(Number a)
{
	return (*this >= a && *this <= a);
}

void Number::operator+=(Number a)
{
	*this = *this + a;
}

void Number::operator-=(Number a)
{
	*this = *this - a;
}