#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)
using namespace std;

class Complex
{
	int re, im;
public:
	Complex();
	Complex(int re, int im);
	~Complex();
	operator char*();
	friend bool operator== (const Complex& a, const Complex& b);
};

Complex operator ""_complex(const char* string, size_t len);

template<typename T>
class Colectie
{
	vector<T> vect;
public:
	Colectie();
	~Colectie();
	void Insert(T elem);
	void Print();
	void Sort();
};

template<typename T>
Colectie<T>::Colectie<T>() {
	vect.clear();
}

template<typename T>
Colectie<T>::~Colectie()
{
	vect.clear();
}

template<typename T>
void Colectie<T>::Insert(T elem)
{
	for (auto it : vect)
		if (it == elem) return;
	vect.push_back(elem);
}

template<typename T>
void Colectie<T>::Print()
{
	for (auto it : vect)
	{
		cout << it << '\n';
	}
	cout << '\n';
}

template<typename T>
void Colectie<T>::Sort()
{
	sort(vect.begin(), vect.end());
}