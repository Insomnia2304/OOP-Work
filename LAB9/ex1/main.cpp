#include "Map.h"

int main()
{
    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    //metodele adaugate
    cout << "----------------------------\n";
    m.Set(50, "tema");
    m.Set(20, "result2");
    const char* p;
    if (m.Get(50, p)) cout << "Valoarea cheii 50: " << p << ".\n";
    else cout << "NU exista cheia 50.\n";
    cout << "Mapa are " << m.Count() << " elemente.\nAcestea sunt:\n";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    cout << "----------------------------\n";

    if (m.Delete(30)) cout << "Am sters valoarea cheii 30.\n";
    else cout << "Nu exista cheia 30 in mapa\n";
    cout << "Acum mapa m arata asa: \n";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    Map<int, const char*> m2;
    Map<int, const char*> m3;

    m2[10] = "aa";
    m2[20] = "bb";

    m3[10] = "aa";
    m3[20] = "bb";
    m3[90] = "cc";

    m.Includes(m2) ? cout << "Mapa m include mapa m2.\n" : cout << "Mapa m nu include mapa m2.\n";
    m.Includes(m3) ? cout << "Mapa m include mapa m3.\n" : cout << "Mapa m nu include mapa m3.\n";

    m3.Clear();
    cout << "Am sters mapa m3.\n";
    cout << "Acum, mapa m3 are: " << m3.Count() << " elemente.\n";
    return 0;
}