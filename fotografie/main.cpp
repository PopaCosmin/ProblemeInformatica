///////////////////////////////
// 2 Decembrie 2014
// Problema fotografie
//5 7
//0 1 0 0 0 1 1
//0 1 0 0 0 1 0
//1 1 1 0 0 0 1
//0 1 1 0 0 0 1
//0 0 0 0 0 1 1

#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;

void Marcare(int a[][MAX], int m, int n, int i, int j, int contor)
{
    a[i][j] = contor;
    if(i > 0 && a[i - 1][j] == 1)
        Marcare(a, m, n, i - 1, j, contor);
    if(j < n - 1 && a[i][j + 1] == 1)
        Marcare(a, m, n, i, j + 1, contor);
    if(i < m - 1 && a[i + 1][j] == 1)
        Marcare(a, m, n, i + 1, j, contor);
    if(j > 0 && a[i][j - 1] == 1)
        Marcare(a, m, n, i, j - 1, contor);
}

void AfisareMatrice(int a[][MAX], int m, int n)
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    ifstream f("input.txt");
    int a[MAX][MAX], i, j, m, n;
    f >> m >> n;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            f >> a[i][j];
    f.close();

    int contor = 2;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            if(a[i][j] == 1)
            {
                Marcare(a, m, n, i, j, contor);
                contor++;
            }
    cout << "Fotografia contine " << contor - 2 << " obiecte" << endl;

    AfisareMatrice(a, m, n);
    return 0;
}
