#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct MoveObject
{
    MoveObject(bool _IsFire, int _Y, int _X) :IsFire(_IsFire), Y(_Y), X(_X) {}
    bool IsFire;
    int Y;
    int X;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // RBLT
    int dY[4] = { 0, 1, 0, -1 };
    int dX[4] = { 1, 0, -1, 0 };

    vector<vector<char>> Maze;
    vector<vector<int>> Visited;
    list<MoveObject> Queue;

    int R, C;
    cin >> R >> C;

    Maze.resize(R, vector<char>(C, '0'));
    Visited.resize(R, vector<int>(C, -1));

    for (int i = 0; i < R; ++i)
    {
        string Input;
        cin >> Input;

        for (int j = 0; j < C; ++j)
        {
            Maze[i][j] = Input[j];

            // 지훈
            if ('J' == Input[j])
            {
                // 지훈이가 제일 먼저 이동 -> push_front
                Queue.push_front(MoveObject(false, i, j));
                Visited[i][j] = 0;
            }

            // 불
            if ('F' == Input[j])
            {
                Queue.push_back(MoveObject(true, i, j));
            }
        }
    }

    // 지훈 = 너비 탐색? 불 = 너비 탐색
    while (false == Queue.empty())
    {
        MoveObject& Now = Queue.front();

        if (Now.IsFire)
        {
            for (int i = 0; i < 4; ++i)
            {
                int NextY = Now.Y + dY[i];
                int NextX = Now.X + dX[i];

                // 범위 체크
                if (0 > NextY || 0 > NextX || R <= NextY || C <= NextX)
                    continue;

                // 벽 & 불 체크
                if ('#' == Maze[NextY][NextX] || 'F' == Maze[NextY][NextX])
                    continue;

                Queue.push_back(MoveObject(true, NextY, NextX));
                Maze[NextY][NextX] = 'F';
            }
        }
        else
        {
            int Turn = Visited[Now.Y][Now.X];

            // 현재 내 위치가 불에 있다
            if ('F' == Maze[Now.Y][Now.X])
            {
                Queue.pop_front();
                continue;
            }

            // 이동
            for (int i = 0; i < 4; ++i)
            {
                int NextY = Now.Y + dY[i];
                int NextX = Now.X + dX[i];

                // 탈출 성공
                if (0 > NextY || 0 > NextX || R <= NextY || C <= NextX)
                {
                    cout << Turn + 1;
                    return 0;
                }

                // 방문여부 & 벽 & 불 체크
                if (0 <= Visited[NextY][NextX] || '#' == Maze[NextY][NextX] || 'F' == Maze[NextY][NextX])
                    continue;

                Queue.push_back(MoveObject(false, NextY, NextX));
                Visited[NextY][NextX] = Turn + 1;
            }
        }
       

        Queue.pop_front();
    }

    cout << "IMPOSSIBLE";


    return 0;
}
