#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*
1. 3 나누기
2. 2 나누기
3. 1 빼기

*/

vector<int> MinOperations;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    MinOperations.resize(N + 1);


    int Index = 2;
    int Prev = 0;
    while (Index <= N)
    {
        int Calc1 = INT32_MAX;
        int Calc2 = INT32_MAX;
        int Calc3 = INT32_MAX;

        if (Index % 3 == 0)
        {
            Calc1 = Index / 3;
            Calc1 = MinOperations[Calc1] + 1;
        }

        if (Index % 2 == 0)
        {
            Calc2 = Index / 2;
            Calc2 = MinOperations[Calc2] + 1;
        }

        Calc3 = Prev + 1;

        Prev = min(min(Calc1, Calc2), Calc3);
        
        MinOperations[Index] = Prev;
        ++Index;
    }

    cout << MinOperations[N];

    return 0;
}