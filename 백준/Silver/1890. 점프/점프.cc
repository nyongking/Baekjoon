#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;




int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    vector<vector<int64_t>> Ways;

    int N;
    cin >> N;

    Ways.resize(N, vector<int64_t>(N, 0));
    Ways[0][0] = 1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int Jump;
            cin >> Jump;

            if (0 == Jump)
                continue;

            for (int d = 0; d < 2; ++d)
            {
                int NextY = i + ((d + 1) % 2) * Jump;
                int NextX = j + (d % 2) * Jump;

                if (NextY >= N || NextX >= N)
                    continue;

                Ways[NextY][NextX] += Ways[i][j];
            }
        }
    }

    cout << Ways[N - 1][N - 1];

    return 0;

}