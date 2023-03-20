#include <iostream>
#include "Math.h"
using namespace std;

int main()
{
	Math x, y, z;
    cout << x.Add(1, 2) << '\n';
    cout << y.Add(1, 2, 3) << '\n';
    cout << z.Add(1.11, 2.22) << '\n';
    cout << x.Add(1.11, 2.22, 3.99) << '\n';
    cout << y.Mul(1, 2)  << '\n';
    cout << z.Mul(1, 2, 3) << '\n';
    cout << x.Mul(7.5, 3.0) << '\n';
    cout << z.Mul(2.5, 2.5, 3.0) << '\n';
    cout << x.Add(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << '\n'; // sums up a list of integers
    cout << y.Add("Lab 3", " POO!") << '\n';
    return 0;
}