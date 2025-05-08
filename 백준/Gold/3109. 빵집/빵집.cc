#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

/*
11x1111111
22122x2222
3x2332x333
433x433xx.
5444544444
.555x55555

11xx11      11xx..
221122      ..1111
..22x.  VS  ....x.
....x.      ....x.
....x.      ....x.

.....
.xx..
..x..
...x.
.....

1xx.1
21x12
x212.
.x2x.
..xx.

1. 위 라인을 타는 것이 좋다.
2. BFS로는 불가능, DFS 사용 - 방문 여부를 되돌릴 수 있어야 한다.

*/

int dY[3] = { -1, 0, 1 };

bool DFS(vector<vector<int>>& Visited, vector<vector<char>>& Graph, int R, int C, int Y, int X, int Count)
{
    Visited[Y][X] = Count;

    // 도착
    if (C - 1 == X)
        return true;

    // 다음 탐색
    for (int i = 0; i < 3; ++i)
    {
        int NextY = Y + dY[i];

        // 범위 체크
        if (0 > NextY || R <= NextY)
            continue;

        // 방문 & 장애물 체크
        if (0 != Visited[NextY][X + 1] || 'x' == Graph[NextY][X + 1])
            continue;

        // 그 다음으로 진행
        // 만약 그래프 연결이 성공 -> 탐색 끝
        if (DFS(Visited, Graph, R, C, NextY, X + 1, Count))
            return true;

        // 방문 여부를 다시 원상복구
        else
        {
            Visited[NextY][X + 1] = 0;
        }
    }

    // 만약 다음으로 진행할 수 없다면 -> 장애물로 만들어버리자
    Graph[Y][X] = 'x';
    return false;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<char>> Graph;
    vector<vector<int>> Visited;
    vector<int> BarrierCount;

    int R, C;
    int MaxBarrier = 0;
    int Answer = 0;

    cin >> R >> C;

    Graph.resize(R, vector<char>(C, '0'));
    Visited.resize(R, vector<int>(C, 0));
    BarrierCount.resize(C, 0);

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> Graph[i][j];

            if ('x' == Graph[i][j])
                ++BarrierCount[j];
        }
    }

    // 최대 장애물 수 확인 -> 답의 최댓값을 알 수 있음
    for (int i = 0; i < C; ++i)
        MaxBarrier = max(MaxBarrier, BarrierCount[i]);

    if (R == MaxBarrier)
    {
        cout << 0;
        return 0;
    }

    else if (0 == MaxBarrier)
    {
        cout << R;
        return 0;
    }

    for (int i = 0; i < R; ++i)
    {
        if (DFS(Visited, Graph, R, C, i, 0, i + 1))
            ++Answer;

        // 이미 최댓값에 도달
        if (Answer == R - MaxBarrier)
            break;
    }

    cout << Answer;

    return 0;
}
