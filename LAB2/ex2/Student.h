#pragma once
class Student
{
	char nume[40];
	float mathGrade, englGrade, histGrade;
public:
	void setNume(char* nume);
	char* getNume();
	void setmathGrade(float x);
	float getmathGrade();

	void setenglGrade(float x);
	float getenglGrade();

	void sethistGrade(float x);
	float gethistGrade();
	bool trecesaunu();

	float average();
};

