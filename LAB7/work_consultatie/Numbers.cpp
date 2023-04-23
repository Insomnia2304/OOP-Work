#include "Numbers.h"

Numbers::Numbers(const char* x)
{
	int i, j;
	for (i = 0, nr = 0; x[i]; i += 8, nr++)
	{
		p[i / 8] = 0;
		for (j = 0; j < 8; j++)
			 p[i / 8] = p[i / 8] * 2 + x[i + j] - '0';
	}
}

int Numbers::getLen(const char* x)
{
	int rez;
	for (rez = 0; x[rez]; rez++);
	return rez;
}

Numbers::Numbers() : nr(0), p{0}
{

}

Numbers::Numbers(const Numbers& x)  : p{0}
{
	bool car[256] = { 0 };
	nr = 0;

	for (int i = 0; i < x.nr; i++)
		if (!car[x.p[i]])
		{
			car[x.p[i]] = 1;
			p[nr++] = x.p[i];
		 }
}

Numbers::~Numbers()
{

}

Numbers::operator short()
{
	return nr;
}

ostream& operator<< (ostream& out, const Numbers& x)
{
	Numbers temp = x;
	sort(temp.p, temp.p + temp.nr);
	for (int i = 0; i < x.nr; i++)
		out << (short)temp.p[i] << ' ';
	return out;
}

Numbers Numbers::operator+(const Numbers& a)
{
	int i;
	Numbers rez;

	for (i = 0; i < nr && i < a.nr; i++)
		rez.p[i] = p[i] + a.p[i];
	if (nr < a.nr)
		rez.nr = nr;
	else rez.nr = a.nr;
	return rez;
}

int Numbers::operator[](int index)
{
	return p[index];
}

int Numbers::min()
{
	int min = p[0];
	for (int i = 0; i < nr; i++)
		if (p[i] < min)
			min = p[i];
	return min;
}

int Numbers::max()
{
	int max = p[0];
	for (int i = 0; i < nr; i++)
		if (p[i] > max)
			max = p[i];
	return max;
}