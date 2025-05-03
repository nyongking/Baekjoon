#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

/*

    2 3 5

    0 1 2 3 4 5 6 7 8 9 10 11 12
    0 0 0 0 0 1 0 0 0 0 2  0  0
    0 0 0 1 0 1 2 0 2 3 2  3  4
    0 0 1 0 2 1 2 2 2 3 2  3  3

    if f(n) == 0
        f(n) = f(n-C) + 1 // f(n-C)가 존재할 때
        f(n) = 0

    else
        f(n) = min(f(n-C), f(n) + 1)
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

    Coins.resize(N, 0);
    MinCoins.resize(K + 1, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> Coins[i];
    }

    // 정렬 후 중복 삭제
    sort(Coins.begin(), Coins.end(), greater<int>());
    auto iter = unique(Coins.begin(), Coins.end());
    Coins.erase(iter, Coins.end());

    N = Coins.size();

    for (int i = 0; i < N; ++i)
    {
        if (0 == MinCoins[Coins[i]])
            MinCoins[Coins[i]] = 1;

        for (int j = Coins[i] + 1; j <= K; ++j)
        {
            if (0 == MinCoins[j])
            {
                if (0 != MinCoins[j - Coins[i]])
                    MinCoins[j] = MinCoins[j - Coins[i]] + 1;
            }
            else
            {
                if (0 != MinCoins[j - Coins[i]])
                    MinCoins[j] = min(MinCoins[j], MinCoins[j - Coins[i]] + 1); 
            }
        }
    }

    if (0 == MinCoins[K])
        cout << -1;
    else
        cout << MinCoins[K];

    return 0;
}
