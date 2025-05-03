#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    제일 작은 동전부터, C1, C2, C3...

    2 3 5
    
    0 1 2 3 4 5 6 7 8

    1 0 1 0 1 0 1 0 1..    
    1 0 1 1 1 1 2 1 1..

*/


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> Combinations;
    vector<int> Coins;
    int N, K;
    
    cin >> N >> K;

    Coins.resize(N);
    Combinations.resize(K + 1, 0);

    Combinations[0] = 1;

    for (int i = 0; i < N; ++i)
    {
        cin >> Coins[i];

        for (int j = Coins[i]; j <= K; ++j)
        {
            Combinations[j] = Combinations[j] + Combinations[j - Coins[i]];
        }
    }

    cout << Combinations[K];

    return 0;
}
