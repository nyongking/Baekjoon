#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // RBLT
    int dY[4] = { 0, 1, 0, -1 };
    int dX[4] = { 1, 0, -1, 0 };
    vector<vector<char>> Graphs(N, vector<char>(M, '0'));
    vector<vector<int>> Visited(N, vector<int>(M, 0));
    list<pair<int, int>> Queue;

    // 그래프 정리
    for (int i = 0; i < N; ++i)
    {
        string Input;
        cin >> Input;

        for (int j = 0; j < M; ++j)
        {
            Graphs[i][j] = Input[j];
        }
    }

    // BFS
    Queue.push_back(make_pair(0, 0));
    Visited[0][0] = 1;

    while (false == Queue.empty())
    {
        pair<int, int> Now = Queue.front();

        // 목적지 도착
        if (N - 1 == Now.first && M - 1 == Now.second)
        {
            cout << Visited[Now.first][Now.second];
            return 0;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextY = Now.first + dY[i];
            int NextX = Now.second + dX[i];

            // 범위 판정
            if (0 > NextX || 0 > NextY || M <= NextX || N <= NextY)
                continue;

            // 갈수 있는 칸
            if ('0' == Graphs[NextY][NextX])
                continue;

            // Visited 판정
            if (0 != Visited[NextY][NextX])
                continue;

            // Queue push
            Queue.push_back(make_pair(NextY, NextX));
            Visited[NextY][NextX] = Visited[Now.first][Now.second] + 1;
        }

        Queue.pop_front();
    }

    return 0;
}
