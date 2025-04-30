#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Point
{
    Point(int _Z, int _Y, int _X) : Z(_Z), Y(_Y), X(_X) {}

    int Z;
    int Y;
    int X;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // RBLTUD
    int dz[6] = { 0, 0, 0, 0, 1, -1 };
    int dy[6] = { 0, 1, 0, -1, 0, 0 };
    int dx[6] = { 1, 0, -1, 0, 0, 0 };

    list<Point> Queue;
    vector<vector<vector<int>>> Tomatoes;
    int M, N, H;

    cin >> M >> N >> H;
    Tomatoes.resize(H, vector<vector<int>>(N, vector<int>(M, 0)));

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                cin >> Tomatoes[i][j][k];
                if (1 == Tomatoes[i][j][k])
                {
                    Queue.push_back(Point(i, j, k));
                }
            }
        }
    }

    int Answer = 0;
    while (false == Queue.empty())
    {
        Point Now = Queue.front();

        if (Answer < Tomatoes[Now.Z][Now.Y][Now.X] - 1)
            Answer = Tomatoes[Now.Z][Now.Y][Now.X] - 1;

        for (int i = 0; i < 6; ++i)
        {
            int NextZ = Now.Z + dz[i];
            int NextY = Now.Y + dy[i];
            int NextX = Now.X + dx[i];

            // 범위 체크
            if (0 > NextZ || 0 > NextY || 0 > NextX || H <= NextZ || N <= NextY || M <= NextX)
                continue;

            // 갈 수 있는 곳 & 이미 방문 구역 체크
            if (0 != Tomatoes[NextZ][NextY][NextX])
                continue;

            Tomatoes[NextZ][NextY][NextX] = Tomatoes[Now.Z][Now.Y][Now.X] + 1;
            Queue.push_back(Point(NextZ, NextY, NextX));
        }

        Queue.pop_front();
    }

    for (auto& XY : Tomatoes)
    {
        for (auto& Line : XY)
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
    }

    cout << Answer;

    return 0;
}
