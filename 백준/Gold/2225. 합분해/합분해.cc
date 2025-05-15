#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*

6 1 = 1 (6)
6 2 = 7 (6 0/5 1/4 2/3 3/2 4/1 5/0 6)
6 3 = (600/510/420/330/240/150/060/501/411/321/231/141/051) ... 

3 3 = (300/210/120/030/201/111/021/102/012/003)
    = f(3, 2) + f(2, 2) + f(1, 2) + f(0, 2)

2 3 = (200/110/020/101/011/002)
    = f(2, 2) + f(1, 2) + f(0, 2)

*/


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> Combinations;
    int N, K;

    cin >> N >> K;

    Combinations.resize(N + 1, vector<int>(K + 1, 0));

    for (int i = 0; i <= K; ++i)
    {
        Combinations[0][i] = 1;
    }

    for (int i = 1; i <= N; ++i)
    {
        Combinations[i][0] = 1;
        if (1 <= K)
            Combinations[i][1] = 1;
        if (2 <= K)
            Combinations[i][2] = i + 1;
    }

    for (int i = 3; i <= K; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            for (int k = 0; k <= j; ++k)
            {
                Combinations[j][i] = (Combinations[j][i] + Combinations[j - k][i - 1]) % 1'000'000'000;
            }
        }
    }

    cout << Combinations[N][K];

    return 0;

}