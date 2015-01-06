// 9 decembrie 2014
// Varianta BAC 1 subiec III problema 4
#include <iostream>

using namespace std;

int sub(int v[], int n, int a)
{
    int contor = 0, i;
    for(i = 0; i < n; i++)
        if(v[i] < a)
            contor++;
    return contor;
}

int main()
{
    int v[100], n, i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> v[i];

    int suma = 0;

    for(i = 0; i < n; i++)
        suma += sub(v, n, v[i]);
    if(suma == (n - 1) * n / 2)
        cout << "DA";
    else
        cout << "NU";

    return 0;
}
