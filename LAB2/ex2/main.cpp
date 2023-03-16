#include <iostream>
#include "Student.h"
#include "Globals.h"
#include <cstring>
using namespace std;

int main()
{
	Student a, b, c;
	a.setNume((char*)"Maria");
	a.setmathGrade(9.55f);
	a.setenglGrade(10.0f);
	a.sethistGrade(9.7f);

	b.setNume((char*)"Ionel");
	b.setmathGrade(1.11f);
	b.setenglGrade(5.0f);
	b.sethistGrade(4.222f);

	c.setNume((char*)"Daniel");
	c.setmathGrade(10.0f);
	c.setenglGrade(4.99f);
	c.sethistGrade(4.222f);

	cout << "Student 1: " << a.getNume() << '\n' << "Notele lui: " << a.getmathGrade() << ", " << a.getenglGrade() << ", " << a.gethistGrade() << ";\nMedia lui este: " << a.average() << "\nStudentul 1 ";
	if (!a.trecesaunu()) cout << "nu ";
	cout << "trece.\n\n";

	cout << "Student 2: " << b.getNume() << '\n' << "Notele lui: " << b.getmathGrade() << ", " << b.getenglGrade() << ", " << b.gethistGrade() << ";\nMedia lui este: " << b.average() << "\nStudentul 2 ";
	if (!b.trecesaunu()) cout << "nu ";
	cout << "trece.\n\n";

	cout << "Student 3: " << c.getNume() << '\n' << "Notele lui: " << c.getmathGrade() << ", " << c.getenglGrade() << ", " << c.gethistGrade() << ";\nMedia lui este: " << c.average() << "\nStudentul 3 ";
	if (!c.trecesaunu()) cout << "nu ";
	cout << "trece.\n\n";
	
	cout << b.getNume() << " este ";
	if (compareByMathGrade(b, c) == 0) cout << "la fel de bun ca ";
	else if (compareByMathGrade(b, c) == -1) cout << "mai prost decat ";
	else cout << "mai bun decat ";
	cout << c.getNume() << " la mate.\n";
	
	cout << b.getNume() << " este ";
	if (compareByEnglGrade(b,c) == 0) cout << "la fel de bun ca ";
	else if (compareByEnglGrade(b,c) == -1) cout << "mai prost decat ";
	else cout << "mai bun decat ";
	cout << c.getNume() << " la engleza.\n";

	cout << b.getNume() << " este ";
	if (compareByHistGrade(b, c) == 0) cout << "la fel de bun ca ";
	else if (compareByHistGrade(b, c) == -1) cout << "mai prost decat ";
	else cout << "mai bun decat ";
	cout << c.getNume() << " la istorie.\n";

	cout << b.getNume() << " este ";
	if (compareByAverage(b, c) == 0) cout << "la fel de bun ca ";
	else if (compareByAverage(b, c) == -1) cout << "mai prost decat ";
	else cout << "mai bun decat ";
	cout << c.getNume() << " la media generala.\n";

	cout << c.getNume() << " este ";
	if (compareByName(c, b) == 0) cout << "langa ";
	else if (compareByName(c, b) == -1) cout << "in fata lui ";
	else cout << "in spatele lui ";
	cout << b.getNume() << " la catalog.\n";
	return 0;
}