#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;



void PrintStar(int N, int Line, int Index)
{
    if (3 == N)
    {
        if (1 == Line % 3 && 1 == Index % 3)
            cout << ' ';
        else
            cout << '*';
    }

    else
    {
        if (1 == (Line / (N / 3)) % 3 && 1 == (Index / (N / 3)) % 3)
            cout << ' ';
        else
            PrintStar(N / 3, Line, Index);
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        *********
        * ** ** * 
        ********* 
        ***   ***
        * *   * *
        ***   ***
        *********
        * ** ** *
        *********

    */
    int Input;
    cin >> Input;

    for (int i = 0; i < Input; ++i)
    {
        for (int j = 0; j < Input; ++j)
        {
            PrintStar(Input, i, j);
        }
        cout << '\n';
    }


    return 0;
}
