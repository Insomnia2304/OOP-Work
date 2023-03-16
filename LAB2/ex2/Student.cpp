#include "Student.h"
#include <cstring>

void Student::setNume(char* nume)
{
	strcpy_s(this->nume, 40, nume);
}

char* Student::getNume()
{
	return this->nume;
}

void Student::setmathGrade(float x)
{
	this->mathGrade = x;
}

float Student::getmathGrade()
{
	return this->mathGrade;
}

void Student::setenglGrade(float x)
{
	this->englGrade = x;
}

float Student::getenglGrade()
{
	return this->englGrade;
}

void Student::sethistGrade(float x)
{
	this->histGrade = x;
}

float Student::gethistGrade()
{
	return this->histGrade;
}

float Student::average()
{
	return (this->mathGrade + this->histGrade + this->englGrade) / 3;
}

bool Student::trecesaunu()
{
	return this->average() >= 5;
}