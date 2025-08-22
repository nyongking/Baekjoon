#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> Graph(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Graph[i][j];
        }
    }

    vector<vector<long long>> dp(N, vector<long long>(M));
    for (int j = 0; j < M; ++j)
    {
        dp[N - 1][j] = Graph[N - 1][j];
    }

    int dX[3] = { -1, 0, 1 };

    for (int i = N - 1; i > 0; --i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (0 == Graph[i][j])
                continue;

            for (int k = 0; k < 3; ++k)
            {
                int NextX = j + dX[k];
                if (0 <= NextX && M > NextX && 1 == Graph[i - 1][NextX])
                {
                    dp[i - 1][NextX] = (dp[i - 1][NextX] + dp[i][j]) % 1'000'000'007;
                }
            }
        }
    }

    int Answer = 0;
    for (int i = 0; i < M; ++i)
    {
        Answer = (Answer + dp[0][i]) % 1'000'000'007;
    }
    cout << Answer;

    return 0;
}