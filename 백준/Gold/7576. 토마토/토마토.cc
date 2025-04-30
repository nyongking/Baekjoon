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

    int M, N;
    cin >> M >> N;

    // RBLT
    int dy[4] = { 0, 1, 0, -1 };
    int dx[4] = { 1, 0, -1, 0 };

    vector<vector<int>> Tomatos(N, vector<int>(M, 0));
    list<pair<int, int>> Queue;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Tomatos[i][j];
            if (1 == Tomatos[i][j])
            {
                Queue.push_back(make_pair(i, j));
            }
        }
    }

    int Answer = 0;
    while (false == Queue.empty())
    {
        pair<int, int> Now = Queue.front();

        if (Answer < Tomatos[Now.first][Now.second] - 1)
            Answer = Tomatos[Now.first][Now.second] - 1;

        for (int i = 0; i < 4; ++i)
        {
            int NextY = Now.first + dy[i];
            int NextX = Now.second + dx[i];

            // 범위 체크
            if (0 > NextY || 0 > NextX || N <= NextY || M <= NextX)
                continue;
           
            // 방문 여부 or 못 가는 곳
            if (0 != Tomatos[NextY][NextX])
                continue;

            Tomatos[NextY][NextX] = Tomatos[Now.first][Now.second] + 1;
            Queue.push_back(make_pair(NextY, NextX));
        }

        Queue.pop_front();
    }
    
    for (auto& Line : Tomatos)
    {
        for (int Tomato : Line)
        {
            if (0 == Tomato)
            {
                cout << -1;
                return 0;
            }
          
        }
    }

    cout << Answer;

    return 0;
}
