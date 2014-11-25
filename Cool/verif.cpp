#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;


ifstream fok("cool.ok");
ifstream fout("cool.out");

void Msg(int pct, string msg );
string Trim(string s);

int main(int argc, char* argv[])
{
    if ( !fout )
        Msg(0, "Nu exista fisierul cool.out!");

    int testNumber, testPoints;
	testNumber =  atoi(argv[1]);          // numarul testului
	testPoints = atoi(argv[2]);          // nr puncte/test

	// doua cerinte
    string a;     // valori corecte
    string x;     // valorile concurentului
    bool ok1 = true, ok2 = true;

    if ( testNumber < 4 )
    {
        getline(fok, a);  a = Trim(a);         // elimin spatiile de la sfarsit
        getline(fout, x); x = Trim(x);
        if ( a != x )
            ok1 = false;
    }
    else
    {
        while ( getline(fok, a) )
        {
            a = Trim(a);
            getline(fout, x);
            x = Trim(x);
            if ( a != x )
                ok2 = false;
        }
    }
    string v = "";
    fout >> v;
    if ( v != "" )
        Msg(0, "Valori suplimentare in cool.out");

	if ( testNumber < 4 )
    {
        if ( ok1 )
            Msg(testPoints, "Corect !");
        else
            Msg(0, "Incorect !");
    }
    else
    {
        if ( ok2 )
            Msg(testPoints, "Corect !");
        else
            Msg(0, "Incorect !");
    }

    return 0;
}

void Msg(int pct, string msg )
{
    cout << pct << ' ' << msg;
    try
    {
        fok.close();
        fout.close();
    }
    catch (string ex) {}
    exit(0);
}

string Trim(string str)
{
	size_t pos = str.find_last_not_of(" \t");
	if ( pos != string::npos )
		str = str.substr(0, pos + 1);
	return str;
}
