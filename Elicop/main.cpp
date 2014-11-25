///////////////////////////////////////////////////////////
// Problema 1 - elicop
// OLimpiada Judeteana de Informatica 2012
// http://olimpiada.info/oji2014/index.php?cid=arhiva
// Autor: Cosmin
// 18 Noiembie 2014
////////////////////////////////////////////////////////

// date test
//    7 9
//    1 1 1 1 1 1 1 1 1
//    0 0 0 0 1 1 1 1 0
//    0 0 1 0 1 1 1 0 0
//    1 1 1 0 1 1 0 1 1
//    0 0 1 1 1 1 0 1 1
//    1 1 1 1 1 1 0 1 1
//    1 1 1 1 1 1 0 0 1
//    4
//    1 1 3 3 -1
//    1 9 5 5 1
//    5 1 6 2 1
//    5 9 6 8 1

#include <iostream>
#include <fstream>
#define MAX 101
#define MAX2 41
using namespace std;

int main()
{
    int m, n, a[MAX][MAX];
    int i, j, k, L1, C1, L2, C2, p;
    int N1 = 0, N2 = 0;
    int e[MAX2] = {0}, r;
    int aux, n0 = 0, n1 = 0;

    ifstream f("elicop.in");

    f >> m >> n;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            f >> a[i][j];
    f >> k;

    for(r = 1; r <= k; r++)
    {
        f >> L1 >> C1 >> L2 >> C2 >> p;
        if(L1 > L2)
        {
            aux = L1; L1 = L2; L2 = aux;
            aux = C1; C1 = C2; C2 = aux;
        }
        n0 = n1 = 0;
        if(C1 < C2 && p == 1)
        {
            for(i = L1; i <= L2; i++)
                for(j = C1 + i - L1; j <= C2; j++)
                    if(a[i][j] == 1)
                        n1++;
                    else
                        n0++;
        }
        if(C1 < C2 && p == -1)
        {
            for(i = L1; i <= L2; i++)
                for(j = C1; j <= C1 + i - L1; j++)
                    if(a[i][j] == 1)
                        n1++;
                    else
                        n0++;
        }
        if(C1 > C2 && p == 1)
        {
            for(i = L1; i <= L2; i++)
                for(j = C2; j <= C1 - (i - L1); j++)
                    if(a[i][j] == 1)
                        n1++;
                    else
                        n0++;
        }
        if(C1 > C2 && p == -1)
        {
            for(i = L1; i <= L2; i++)
                for(j = C1 - (i - L1); j <= C1; j++)
                    if(a[i][j] == 1)
                        n1++;
                    else
                        n0++;
        }
        if(n0 == 0)
            N1++;
        else if(n0 > n1)
        {
            N2++;
            e[N2] = r;
        }

    }
    f.close();

    ofstream g("elicop.out");
    g << N1 << endl;
    g << N2 << " ";
    for(i = 1; i <= N2; i++)
        g << e[i] << " ";

    return 0;
}
