#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    f0 = (1, 0)
    f1 = (0, 1)
    f2 = f1 + f0 = (1, 1)
    f3 = f2 + f1 = f1 + f0 + f0
    f4 = f3 + f2 = ..

    f(N) = f(N-1) + f(N-2)
*/

vector<pair<int, int>> Fibonaccis;

pair<int, int> FibonacciFunc(int N)
{
    if (-1 == Fibonaccis[N].first)
    {
        pair<int, int> Result;
        if (0 == N)
        {
            Result = make_pair(1, 0);
        }
        else if (1 == N)
        {
            Result = make_pair(0, 1);
        }
        else
        {
            pair<int, int> Result1 = FibonacciFunc(N - 1);
            pair<int, int> Result2 = FibonacciFunc(N - 2);

            Result = make_pair(Result1.first + Result2.first, Result1.second + Result2.second);
        }

        Fibonaccis[N] = Result;

        return Result;
    }
    else
    {
        return Fibonaccis[N];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int N;
        cin >> N;

        if (Fibonaccis.size() < N + 1)
        {
            Fibonaccis.resize(N + 1, make_pair(-1, -1));

            FibonacciFunc(N);
        }


        cout << Fibonaccis[N].first << ' ' << Fibonaccis[N].second << '\n';

    }


    return 0;
}
