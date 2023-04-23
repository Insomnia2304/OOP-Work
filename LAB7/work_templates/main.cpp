#include "Complex.h"

int main()
{
    srand(time(0));

    Complex c1 = "50+100j"_complex;
    cout << c1 << endl;

    Colectie<int> col1;
    for (int i = 0; i < 10; i++)
        col1.Insert(i ^ 41);
    col1.Sort();
    col1.Print();
    cout << endl;

    Colectie<char> col2;
    for (int i = 0; i < 10; i++)
        col2.Insert('z' - (i ^ 5));
    col2.Sort();
    col2.Print();
    cout << endl;

    
    Colectie<Complex> col3;
    for (int i = 0; i < 10; i++)
        col3.Insert({ rand() % 30, rand() % 30});
    col3.Sort();
    col3.Print();
    cout << endl;

    return 0;
}