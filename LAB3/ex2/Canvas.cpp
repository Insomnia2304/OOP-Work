#include "Canvas.h"
#include <iostream>
using namespace std;

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	m = new char*[height];
	for (int i = 0; i < height; i++)
	{
		m[i] = new char[width + 1];
		m[i][width] = 0;
	}
	Clear(); //banuiesc ca apeland asa are acces la this, sper sa am dreptate (am testat si avea)
}

Canvas::~Canvas()
{
	for (int i = 0; i < height; i++)
		delete[] m[i];
	delete[] m;
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
		memset(m[i], 32, 10);
}

void Canvas::Print() // shows what was printed
{
	for (int i = 0; i < height; i++)
	{
		cout << m[i] << '\n';
	}
	cout << "\n--------------------------------------\n\n";
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	int i;
	for (i = top; i <= bottom; i++) m[i][left] = m[i][right] = ch;
	for (i = left; i <= right; i++) m[top][i] = m[bottom][i] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	int i, j;
	for (int i = top; i <= bottom; i++)
		for (j = left; j <= right; j++)
			m[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	m[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{///x - abscisa, y - ordonata
 ///the algorithm fails for completely vertical lines
 /*
 Notably, the basic form of the Braseham algorithm only covers one octant of the circle:
 the one where the line has increasing X and Y coordinates 
 but a negative slope with an absolute value less than 1. 
 All other octants can be derived as simple transformations of this basic octant.
 */
	int dx, dy, x, y, D;
	dx = x2 - x1;
	dy = y2 - y1;
	D = 2 * dy - dx;
	y = y1;
	for (x = x1; x <= x2; x++)
	{
		m[y][x] = ch;
		if (D > 0)
		{
			y = y + 1;
			D = D - 2 * dx;
		}

		D = D + 2 * dy;
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	if (x - ray < 0 || y - ray < 0 || x + ray >= width || y + ray >= height)
		return;
	FillCircle(x, y, ray, ch);
	if (ray > 0)
		FillCircle(x, y, ray - 1, 32);
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	if (x - ray < 0 || y - ray < 0 || x + ray >= width || y + ray >= height)
		return;
	int i, j;
	for (i = -ray; i <= ray; i++)
		for (j = -ray; j <= ray; j++)
			if (i * i + j * j <= ray * ray)
				m[y + j][x + i] = ch;
}