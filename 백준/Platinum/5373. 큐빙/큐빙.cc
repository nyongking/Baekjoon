#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    윗 : 흰색
    아래 : 노랑
    앞 : 빨강
    뒤 : 오렌지
    왼 : 초록
    오 : 파랑

    윗면 ?
*/

#define UP 0
#define DOWN 1
#define FORWARD 2
#define BACK 3
#define LEFT 4
#define RIGHT 5

char Colors[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };


void Rotate(vector<vector<char>>& Cube, string& Command)
{
    vector<int> Surfaces(4, -1);
    vector<vector<int>> Rotates(4, vector<int>(3, -1));
    vector<vector<int>> SurfaceRotates(2, vector<int>());
    int Surface = -1;

    if ('U' == Command[0])
    {
        Surfaces = {BACK, RIGHT, FORWARD, LEFT};
        Rotates = { {2, 1, 0}, {2, 1, 0}, {2, 1, 0}, {2, 1, 0} };
        Surface = UP;
    }

    else if ('D' == Command[0])
    {
        Surfaces = { BACK, LEFT, FORWARD, RIGHT };
        Rotates = { {6, 7, 8}, {6, 7, 8}, {6, 7, 8}, {6, 7, 8} };
        Surface = DOWN;
    }

    else if ('F' == Command[0])
    {
        Surfaces = { UP, RIGHT, DOWN, LEFT };
        Rotates = { {6, 7, 8}, {0, 3, 6}, {6, 7, 8}, {8, 5, 2} };
        Surface = FORWARD;
    }

    else if ('B' == Command[0])
    {
        Surfaces = { UP, LEFT, DOWN, RIGHT };
        Rotates = { {2, 1, 0}, {0, 3, 6}, {2, 1, 0}, {8, 5, 2} };
        Surface = BACK;
    }

    else if ('L' == Command[0])
    {
        Surfaces = { UP, FORWARD, DOWN, BACK };
        Rotates = { {0, 3, 6}, {0, 3, 6}, {8, 5, 2}, {8, 5, 2} };
        Surface = LEFT;
    }

    else if ('R' == Command[0])
    {
        Surfaces = { UP, BACK, DOWN, FORWARD };
        Rotates = { {8, 5, 2}, {0, 3, 6}, {0, 3, 6}, {8, 5, 2} };
        Surface = RIGHT;
    }


    int Index = 0;
    char Line[3];
    if ('+' == Command[1])
    {
        SurfaceRotates[0] = vector<int>{0, 2, 8, 6};
        SurfaceRotates[1] = vector<int>{1, 5, 7, 3};

        for (int i = 0; i < 3; ++i)
            Line[i] = Cube[Surfaces[Index]][Rotates[Index][i]];

        while (true)
        {
            ++Index;

            if (3 < Index)
            {
                Index = 0;
                for (int i = 0; i < 3; ++i)
                    Cube[Surfaces[Index]][Rotates[Index][i]] = Line[i];

                break;
            }


            for (int i = 0; i < 3; ++i)
            {
                char Temp;
               
                Temp = Cube[Surfaces[Index]][Rotates[Index][i]];
                Cube[Surfaces[Index]][Rotates[Index][i]] = Line[i];
                Line[i] = Temp;
            }           
        }
    }
    else if ('-' == Command[1])
    {
        SurfaceRotates[0] = vector<int>{ 0, 6, 8, 2 };
        SurfaceRotates[1] = vector<int>{ 1, 3, 7, 5 };

        Index = 3;

        for (int i = 0; i < 3; ++i)
            Line[i] = Cube[Surfaces[Index]][Rotates[Index][i]];

        while (true)
        {
            --Index;

            if (0 > Index)
            {
                Index = 3;
                for (int i = 0; i < 3; ++i)
                    Cube[Surfaces[Index]][Rotates[Index][i]] = Line[i];

                break;
            }


            for (int i = 0; i < 3; ++i)
            {
                char Temp;

                Temp = Cube[Surfaces[Index]][Rotates[Index][i]];
                Cube[Surfaces[Index]][Rotates[Index][i]] = Line[i];
                Line[i] = Temp;
            }
        }
    }

    //// 면 자체에서 회전
    for (int i = 0; i < 2; ++i)
    {
        char Now = Cube[Surface][SurfaceRotates[i][0]];
        for (int j = 1; j <= 4; ++j)
        {
            char temp = Cube[Surface][SurfaceRotates[i][j % 4]];
            Cube[Surface][SurfaceRotates[i][j % 4]] = Now;
            Now = temp;
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        vector<vector<char>> Cube(6, vector<char>());

        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 9; ++j)
                Cube[i].push_back(Colors[i]);
        }

        int Case;
        cin >> Case;

        for (int i = 0; i < Case; ++i)
        {
            string Command;
            cin >> Command;

            Rotate(Cube, Command);
        }

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
                cout << Cube[UP][i * 3 + j];
            cout << '\n';
        }


    }


    return 0;
}
