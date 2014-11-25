#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 100000

using namespace std;

void Print(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void InsertionSort(int a[], int n)
{
    int i, j, key;
    for (j = 1; j < n; j++)
    {
        key = a[j];
        i = j - 1;
        while(i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}


void SelectionSort(int a[], int n)
{
    int i, j, min, aux;
    for(i = 0; i < n; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
            if(a[j] < a[min])
                min = j;
        aux = a[i];
        a[i] = a[min];
        a[min] = aux;

    }

}



void InitializareVector(int a[], int n, int min, int max)
{
    srand (time(NULL));
    for(int i = 0; i < n; i++)
        a[i] = rand() % (max - min) + min;
}
int main()
{
    //int a[] = {5, 2, 4, 1, 3, 6};

    int a[N] = {0};
    int n = N;

    n = sizeof(a) / sizeof (a[0]);

    cout << "Initializing...";
    InitializareVector(a, n, 1, 1000);
    cout << "done" << endl;



    //Print(a, n);
    cout << "Sorting...";
    SelectionSort(a, n);
    cout << "done" << endl;
    //Print(a, n);

    return 0;
}
