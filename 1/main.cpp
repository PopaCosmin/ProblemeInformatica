#include <iostream>

using namespace std;

void Citire(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        cin >> a[i];
}

void Afisare(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int imax(int a[], int n)
{
    int i_max = 0, i;
    for(i = 1; i < n; i++)
        if(a[i] > a[i_max])
            i_max = i;

    return i_max;
}

int main()
{
    cout << "Hello world!" << endl;
    int n, a[100];

    cin >> n;
    Citire(a, n);


    cout << "numerele citite sunt: ";
    Afisare(a, n);


    cout << "valoarea maxima se afla pe pozitia " << imax(a, n) << endl;

    return 0;
}
