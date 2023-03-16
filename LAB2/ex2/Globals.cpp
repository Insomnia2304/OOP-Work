#include "Globals.h"
#include <cstring>

int compareByEnglGrade(Student& a, Student& b)
{
	if (a.getenglGrade() < b.getenglGrade()) 
		return -1;
	return a.getenglGrade() > b.getenglGrade();
}

int compareByHistGrade(Student& a, Student& b)
{
	if (a.gethistGrade() < b.gethistGrade())
		return -1;
	return a.gethistGrade() > b.gethistGrade();
}

int compareByMathGrade(Student& a, Student& b)
{
	if (a.getmathGrade() < b.getmathGrade())
		return -1;
	return a.getmathGrade() > b.getmathGrade();
}

int compareByAverage(Student& a, Student& b)
{
	if (a.average() < b.average())
		return -1;
	return a.average() > b.average();
}

int compareByName(Student& a, Student& b)
{
	int x = strcmp(a.getNume(), b.getNume());
	if (x < 0) return -1;
	return x > 0;
}