#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*

50 45 37 32 30
35 50 40 20 25
30 30 25 17 28
27 24 22 15 10

1 1 1 1 1
1 0 0 2 1
1 0 0 2 0
1 1 1 3 3

*/
vector<vector<bool>> Visited;
vector<vector<int>> Way;
vector<vector<int>> Graph;
int N, M;

int dY[4] = { 0, 1, 0, -1 };
int dX[4] = { 1, 0, -1, 0 };

int ComputeWayCount(int X, int Y)
{
    if (false == Visited[Y][X])
    {
        for (int i = 0; i < 4; ++i)
        {
            int AdjY = Y + dY[i];
            int AdjX = X + dX[i];

            if (0 > AdjY || 0 > AdjX || N <= AdjY || M <= AdjX)
                continue;

            if (Graph[Y][X] < Graph[AdjY][AdjX])
            {
                Way[Y][X] += ComputeWayCount(AdjX, AdjY);
            }

        }

        Visited[Y][X] = true;
    }

    return Way[Y][X];

}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    Graph.resize(N, vector<int>(M, 0));
    Way.resize(N, vector<int>(M, 0));
    Visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Graph[i][j];
        }
    }

    Visited[0][0] = true;
    Way[0][0] = 1;

    cout << ComputeWayCount(M - 1, N - 1);


    return 0;

}