#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int64_t> Fibonaccis;

int64_t CalcPeriod(int Div)
{
    int First = 0, Second = 1;
    int64_t Period = 1;

    while (true)
    {
        int NextF = Second;
        int NextS = (First + Second) % Div;

        if (0 == NextF && 1 == NextS)
        {
            return Period;
        }
        else
        {
            First = NextF;
            Second = NextS;
            ++Period;
        }
    }
}

int GetFibonacciValue(int64_t Index, int64_t Period, int Div)
{
    Index = Index % Period;

    if (0 == Index)
        return 0;
    else if (1 == Index)
        return 1;
    else
    {
        Fibonaccis.resize(static_cast<size_t>(Index + 1), 0ll);
        Fibonaccis[0] = 0;
        Fibonaccis[1] = 1;
    }

    for (int64_t i = 2; i <= Index; ++i)
    {
        Fibonaccis[i] = (Fibonaccis[i - 1] + Fibonaccis[i - 2]) % Div;
    }

    return Fibonaccis[Index];
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int64_t Period = CalcPeriod(1'000'000);

    int64_t N;
    cin >> N;

    cout << GetFibonacciValue(N, Period, 1'000'000);

}