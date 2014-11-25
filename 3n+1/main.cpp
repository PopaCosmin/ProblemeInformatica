#include <iostream>

using namespace std;

int GenerareSecventa(int n, int &max, int flag)
{
    int contor = 0;
    if (flag == 1)
            cout << n << ": ";
    while (n != 1)
    {
        contor++;
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
        if (n > max)
            max = n;
        if (flag == 1)
            cout << n << " ";
    }
    if (flag == 1)
        cout << endl;
    return contor;
}

int main()
{
    int n, lungimeSecventa;
    int max = 0;
    cin >> n;
    max = n;
    lungimeSecventa = GenerareSecventa(n, max, 1); // apel al functiei
    cout << "lungimea secventei: " << lungimeSecventa << endl;
    cout << "valoarea maxima din secventa este: " << max << endl;

    int a, b;
    int lungimeMaxima = 0;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        lungimeSecventa = GenerareSecventa(i, max, 1);
        if (lungimeSecventa > lungimeMaxima)
            lungimeMaxima = lungimeSecventa;
    }

    cout << "in intervalul [" << a << ", " << b << "] lungimea maxima de secventa este: " << lungimeMaxima << endl;
    cout << "si se obtine pentru urmatoarele valori: ";
    for (int i = a; i <= b; i++)
    {
        lungimeSecventa = GenerareSecventa(i, max, 0);
        if (lungimeSecventa == lungimeMaxima)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
