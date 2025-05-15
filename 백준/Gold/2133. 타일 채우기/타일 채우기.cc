#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*
    3 2 2 2 2 2..
    
    f(2) = T(2)
    f(4) = T(2) * T(2) + T(4)
    f(6) = T(2) * T(2) * T(2) + T(4) * T(2) + T(2) * T(4) + T(6)
    ->
    f(8) = T(2) * f(6) + T(4) * f(4) + T(6) * f(2) + T(8) * f(0)
    f(2) = T(2) * f(0)
*/


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> Counts;
    vector<int> TileCases;
    int N;

    cin >> N;

    TileCases.resize(N + 1, 0);
    Counts.resize(N + 1, 0);

    if (1 == N % 2)
    {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (2 == i)
            TileCases[i] = 3;
        else if (0 == i % 2)
            TileCases[i] = 2;
    }
    Counts[0] = 1;

    for (int i = 2; i <= N; i += 2)
    {
        for (int j = 2; j <= i; j += 2)
        {
            Counts[i] += TileCases[j] * Counts[i - j];
        }
    }

    cout << Counts[N];



    return 0;

}