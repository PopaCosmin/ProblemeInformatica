#include <iostream>
#include <fstream>

using namespace std;

int cool(int C[], int min, int max, int K)
{
    int ok = 1;
    if(max - min + 1 != K)
        return 0;
    for(int i = min; i <= max && ok == 1; i++)
        if (C[i] != 1)
            ok = 0;

    return ok;
}

void C1(int N, int K, int A[])
{
    int C[1001] = {0};
    int min = 1001, max = 0, contor = 0;

    ofstream g("cool.out");

    for (int i = 1; i <= K; i++)
    {
        if (min > A[i])
            min = A[i];
        if (max < A[i])
            max = A[i];
        C[A[i]]++;
    }
    if (cool(C, min, max, K))
        g << max;
    else{
        for(int i = min; i <= max; i++)
            if(C[i] == 1)
                contor++;
        g << contor;
    }

    g.close();

}
void C2(int N, int A[])
{
    int K, contor;
    ofstream g("cool.out");
    for(K = N; K >= 1; K--)
    {
        contor = 0;
        for(j = 1; j <= N - K + 1; j++)
        {
            // verific daca secventa de la j la j + k -1 este cool
            for(i = j; i <= j + K - 1)
            {


            }
            // daca este contor ++
        }
        if(contor > 0)
        {
            g >> K >> endl;
            g >> contor;
            g.close();
            break;
        }
    }
}
int main()
{
    int N, K, A[5001], p;

    ifstream f("3-cool.in");

    f >> p >> N >> K;
    for(int i = 1; i <= N; i++)
        f >> A[i];
    f.close();

    if(p == 1)
        C1(N, K, A);
    else if(p == 2)
        C2(N, A);
    else
        cout << "Date incorecte";


    return 0;
}
