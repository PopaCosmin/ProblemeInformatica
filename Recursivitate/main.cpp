#include <iostream>

using namespace std;
void f(long n, int i)
{
    if(n!=0)
        if(n%3>0)
        {
            cout<<i;
            f(n/3,i+1);
        }
}


int SumaCifre(int n)
{
    if(n == 0)
        return 0;
    else
        return n % 10 + SumaCifre(n / 10);
}

int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);

}

void Oglindit(int n)
{
    if (n > 0)
    {
        cout << n % 10;
        Oglindit(n / 10);
    }
}

int main()
{
    // varianta 1 bac
    f(121, 1);

    // determinarea sumei cifrelor unui numar cu o suma recursiva
    cout << endl << SumaCifre(176) << endl;

    // generare element din sirul lui Fibonacci
    cout << fib(10) << endl;

    // generarea oglinditului unui numar
    Oglindit(3275);

    return 0;
}
