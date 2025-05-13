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

    int dY[3] = { 1, 0, 1 };
    int dX[3] = { 0, 1, 1 };

    vector<vector<int>> MaxCandy;
    int N, M;

    cin >> N >> M;
    MaxCandy.resize(N, vector<int>(M, 0));


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int Candy;
            cin >> Candy;

            MaxCandy[i][j] += Candy;

            for (int d = 0; d < 3; ++d)
            {
                int NextY = i + dY[d];
                int NextX = j + dX[d];

                if (NextY < N && NextX < M)
                {
                    MaxCandy[NextY][NextX] = max(MaxCandy[NextY][NextX], MaxCandy[i][j]);
                }
            }

        }
    }

    cout << MaxCandy[N - 1][M - 1];

    return 0;

}