#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdarg.h>
#include <stdlib.h>
#include <cstring>

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return x + y;
}

int Math::Add(double x , double y , double z)
{
	return x + y + z;
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return x * y;
}

int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int Math::Add(int count, ...) // sums up a list of integers
{
	int res = 0;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count ; i++)
	{
		res += va_arg(vl, int);
	}
	va_end(vl);
	return res;
}

char* Math::Add(const char* s1, const char* s2)
{
	char* p = (char*)malloc(strlen(s1) + strlen(s2));
	strcpy(p, s1);
	strcat(p, s2);
	return p;
}