#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

typedef
enum Commands
{
    Move, Pile, Quit
} COMMANDS;

typedef
enum CommandTypes
{
    onto, over
}COMMAND_TYPES;

struct Command
{
    COMMANDS name;
    int from, to;
    COMMAND_TYPES type;
};

void InitBlocks (int a[][25], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        a[i][0] = i;
        for(j = 1; j < n; j++)
            a[i][j] = -1;
    }
}

void PrintResult (int a[][25], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        cout << i << ": ";
        for(j = 0; j < n && a[i][j]  != -1; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void ProcessCommand (int a[][25], int n, struct Command c)
{
//TODO
}

void PrintCommand (struct Command c)
{
    switch(c.name)
    {
    case Move:
        cout << "Move ";
        break;
    case Pile:
        cout << "Pile ";
        break;
    }

    cout << c.from << " ";

    switch(c.type)
    {
    case onto:
        cout << "Onto ";
        break;
    case over:
        cout << "Over ";
        break;
    }
    cout << c.to << endl;
}

int main()
{

    struct Command c;
    int n;
    int a[25][25];
    char buffer[10];
    ifstream f("input.in");

    f >> n;
    InitBlocks (a, n);

    do
    {
        f >> buffer;
        if(strcmp(buffer, "move") == 0)
            c.name = Move;
        else if(strcmp(buffer, "pile") == 0)
            c.name = Pile;
        else if(strcmp(buffer, "quit") == 0)
            c.name = Quit;
        else
        {
            cout << "Unknown command" << endl;
            return -1;
        }

        if(c.name == Quit)
        {
            f.close();
            break;
        }

        f >> c.from;

        f >> buffer;
        if(strcmp(buffer, "onto") == 0)
            c.type = onto;
        else if(strcmp(buffer, "over") == 0)
            c.type = over;
        else{
            cout << "Invalid command type" << endl;
            return -1;
        }

        f >> c.to;

        ProcessCommand(a, n, c);

        PrintCommand(c);

    } while(1);

    PrintResult(a, n);

    return 0;
}
