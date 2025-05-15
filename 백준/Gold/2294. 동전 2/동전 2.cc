#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*


*/


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> MinCoins;
    vector<int> Coins;
    int N, K;

    cin >> N >> K;
    Coins.resize(N);
    MinCoins.resize(K + 1);

    for (int i = 0; i < N; ++i)
    {
        cin >> Coins[i];
    }

    {
        sort(Coins.begin(), Coins.end());
        auto iter = unique(Coins.begin(), Coins.end());
        Coins.erase(iter, Coins.end());
    }

    for (int i = 0; i < Coins.size(); ++i)
    {
        if (K >= Coins[i])
            MinCoins[Coins[i]] = 1;
    }

    for (int i = 1; i <= K; ++i)
    {
        if (1 == MinCoins[i])
            continue;

        for (int j = 0; j < Coins.size(); ++j)
        {
            int Remain = i - Coins[j];

            if (0 > Remain)
                break;

            if (0 == MinCoins[Remain])
                continue;

            if (0 == MinCoins[i])
                MinCoins[i] = MinCoins[Remain] + 1;
            else
                MinCoins[i] = min(MinCoins[i], MinCoins[Remain] + 1);

        }
    }
    
    if (MinCoins[K])
        cout << MinCoins[K];
    else
        cout << -1;

    return 0;

}