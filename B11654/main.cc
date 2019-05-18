#include <iostream>

using namespace std;

class Solver
{
    char input;

    void GetArgs()
    {
        input = getchar();
    }

public:

    int Solve()
    {
        GetArgs();
        return (int)input;
    }

};

int main()
{
    Solver a = Solver();
    cout << a.Solve() << endl;
}