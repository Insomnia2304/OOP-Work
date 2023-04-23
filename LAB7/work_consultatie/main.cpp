#include "Numbers.h"

int main()
{
    int curent;
    Numbers n = "1010111010100011101011101010111101110001001000101110100000111111001111111101110010000001000100011110100111111111100110010001000110101110";
    short count = n;
    cout << "Elementele initiale:" << endl;
    for (short i = 0; i < count; i++)
    {
        curent = n[i];
        cout << curent << " ";
    }
    cout << endl;

    int sum_min_max = n.min() + n.max();
    cout << endl << "suma min + max = " << sum_min_max << endl;

    Numbers unice = n;
    count = unice;
    cout << endl << "Elementele unice:" << endl;
    for (short i = 0; i < count; i++)
    {
        curent = unice[i];
        cout << curent << " ";
    }
    cout << endl;
    cout << endl << "Elementele unice sortate:" << endl << unice << endl;

    Numbers suma = n + unice;
    count = suma;
    cout << endl << "Suma numerelor:" << endl;
    for (short i = 0; i < count; i++)
    {
        curent = suma[i];
        cout << curent << " ";
    }
    cout << endl;

    return 0;
}