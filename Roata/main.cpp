////////////////////////////////////////////
// Problema 2  Roata OJI 2012 clasa IX
//25.11.2014
// Date test
//4
//7
//6 4 1 5 2 8 3
//////////////////////////////////////////


#include <iostream>
#include <fstream>
#define MAX 100000
#define MAX_CABINE 360

using namespace std;

int Suma(int c[], int p)
{
    int i, s = 0;
    for(i = 1; i <= p; i++)
        s = s + c[i];
    return s;
}

int main()
{
    ifstream f("roata.in");
    int n, p, c[MAX + 1] = {0};
    int i, j;
    int r_cab[MAX_CABINE + 1] = {0}, p_cab[MAX + 1] = {0};
    int cabineGoale;

    f >> n >> p;
    for(i = 1; i <= p; i++)
        f >> c[i];
    f.close();

    ofstream g("roata.out");

    g << Suma(c, p) << endl;

    cabineGoale = n;
    i = 1; j = 1;
    while(cabineGoale < n || i <= p)
    {
        if(r_cab[j] == 0)
        {
            if(p_cab[j] != 0)
            {
                g << p_cab[j] << " ";
                p_cab[j] = 0;
                cabineGoale++;
            }
            if(i <= p)
            {
                r_cab[j] = c[i] - 1;
                p_cab[j] = i;
                cabineGoale--;
                i++;
            }

        }
        else{
            r_cab[j]--;

        }
        j++;
        if(j == n + 1)
            j = 1;
    }
    j--;
    if(j == 0)
        j = n;
    g << endl << j;
    g.close();
    return 0;
}
