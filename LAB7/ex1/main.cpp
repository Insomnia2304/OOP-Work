#include <iostream>
using namespace std;

float operator"" _Kelvin(unsigned long long int x);
float operator"" _Fahrenheit(unsigned long long int x);

int main() {

    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout << a << ' ' << b << '\n';
    return 0;
}

float operator"" _Kelvin(unsigned long long int x)
{
    return x - 273.15f;
}

float operator"" _Fahrenheit(unsigned long long int x)
{
    return (x - 32) / 1.8f;
}