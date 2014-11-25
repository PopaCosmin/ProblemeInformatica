#include <iostream>
#include <fstream>
#define MAX 100

using namespace std;

void NF(int w[], int n, int C, int bin[])
{
    int suma = 0, i;
    int currentBin = 1;
    for(i = 0; i < n; i++)
    {
        if (suma + w[i] <= C)
        {
            bin[i] = currentBin;
            suma = suma + w[i];
        }
        else
        {
            currentBin++;
            bin[i] = currentBin;
            suma = w[i];
        }
    }
}

void PrintBins(int w[], int n, int bin[])
{
    int max = 0, i, j;
    for(i = 0; i < n; i++)
        if (bin[i] > max)
            max = bin[i];

    for(i = 1; i <= max; i++)
    {
        cout << i << ": ";
        for(j = 0; j < n; j++)
            if(bin[j] == i)
                cout << w[j] << " ";
        cout << endl;
    }
}

void ResetBin(int bin[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        bin[i] = 0;
}
int BinSum(int j, int bin[], int w[], int n)
{
    int suma = 0;
    for(int i = 0; i< n; i++)
        if (bin[i] == j)
            suma = suma + w[i];
    return suma;
}
// greutatea curenta se pune in primul container deschis in care incape
void FF(int w[], int n, int C, int bin[])
{
    int nrBins = 1;
    int i, j, suma;
    for (i = 0; i < n; i++)
    {
        for(j = 1; j <= nrBins; j++)
        {
            suma = BinSum(j, bin, w, n);
            if(suma + w[i] <= C)
            {
                bin[i] = j;
                break;
            }
        }
        if(j > nrBins)
        {
            nrBins++;
            bin[i] = nrBins;
        }

    }
}



int main()
{
    ifstream f("date.in");
    int C, n, i;
    int w[MAX] = {0};
    int bin[MAX] = {0};

    f >> C;
    f >> n;
    for(i = 0; i < n; i++)
        f >> w[i];
    f.close();


    NF(w, n, C, bin);
    PrintBins(w, n, bin);

    ResetBin(bin, n);
    FF(w, n, C, bin);
    PrintBins(w, n, bin);

    return 0;
}
