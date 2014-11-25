#include <iostream>
#define MAX 100

using namespace std;

//////////////////////
// permutari
/////////////////////
void init(int v[], int k)
{
    v[k] = 0;
}
int succesor(int v[], int k, int n)
{
    int as = 0;
    if(v[k] < n)
    {
        v[k]++;
        as = 1;
    }
    return as;
}

int valid(int v[], int k, int n)
{
    int ev = 1;
    int i;
    for(i = 0; i < k && ev == 1; i++)
        if(v[i] == v[k])
            ev = 0;
    return ev;
}

int solutie(int v[], int k, int n)
{
//    if (k == n - 1)
//        return 1;
//    else
//        return 0;
    return (k == n - 1);
}

void tipar( int v[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

void Permutari(int n)
{
    int k = 0;
    int v[MAX] = {0};
    int as, ev;

    init(v, k);

    while(k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if(as)
                ev = valid(v, k, n);
        }while(as && !ev);
        if(as)
            if(solutie(v, k, n))
                tipar(v, n);
            else
            {
                k++;
                init(v, k);
            }
        else
            k--;
    }
}


//////////////////////////
// produs cartezian
/////////////////////////


int validPC(int v[], int k, int n)
{
   return 1;
}

void ProdusCartezian(int n)
{
     int k = 0;
    int v[MAX] = {0};
    int as, ev;

    init(v, k);

    while(k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if(as)
                ev = validPC(v, k, n);
        }while(as && !ev);
        if(as)
            if(solutie(v, k, n))
                tipar(v, n);
            else
            {
                k++;
                init(v, k);
            }
        else
            k--;
    }
}

///////////////////
// aranjamente
//////////////////
void Aranjamente(int n, int r)
{
    int k = 0;
    int v[MAX] = {0};
    int as, ev;

    init(v, k);

    while(k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if(as)
                ev = valid(v, k, n);
        }while(as && !ev);
        if(as)
            if(solutie(v, k, r))
                tipar(v, r);
            else
            {
                k++;
                init(v, k);
            }
        else
            k--;
    }
}


///////////////////
// combinari
//////////////////
void initCmb(int v[], int k)
{
    if (k == 0)
        v[k] = 0;
    else
        v[k] = v[k - 1];
}

void Combinari(int n, int r)
{
    int k = 0;
    int v[MAX] = {0};
    int as, ev;

    initCmb(v, k);

    while(k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if(as)
                ev = valid(v, k, n);
        }while(as && !ev);
        if(as)
            if(solutie(v, k, r))
                tipar(v, r);
            else
            {
                k++;
                initCmb(v, k);
            }
        else
            k--;
    }
}
int main()
{
    int n = 0;
    int k = 0;

    cout << "n= ";
    cin >> n;

    cout << "Permutari\n";
    Permutari(n);

    cout << "Produs Cartezian\n";
    ProdusCartezian(n);

    cout << "k=";
    cin >> k;
    cout << "Aranjamente\n";
    Aranjamente(n, k);

    cout << "Combinari\n";
    Combinari(n, k);
    return 0;
}
