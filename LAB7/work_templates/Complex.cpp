#include "Complex.h"

Complex operator ""_complex(const char* string, size_t len)
{
	int re, im;
	sscanf(string, "%d+%d", &re, &im);
	return Complex(re, im);
}

Complex::Complex() :re(0), im(0) {}
Complex::Complex(int re, int im) :re(re), im(im) {}
Complex::~Complex() {}

Complex::operator char*()
{
	static char string[100];
	sprintf(string, "Re: %d Im: %d", re, im);
	return string;
}

bool operator== (const Complex& a, const Complex& b)
{
	return (a.re == b.re && a.im == b.im);
}