#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int Answer = 0;

// RBLT
int dY[4] = { 0, 1, 0, -1 };
int dX[4] = { 1, 0, -1, 0 };

void DFS(vector<vector<char>>& Graphs, vector<bool>& Visited, int R, int C, int NowY, int NowX, int Move)
{
    ++Move;
    
    if (Move > Answer)
        Answer = Move;

    for (int i = 0; i < 4; ++i)
    {
        int NextY = NowY + dY[i];
        int NextX = NowX + dX[i];

        // 범위 체크
        if (0 > NextY || 0 > NextX || R <= NextY || C <= NextX)
            continue;

        // 방문 여부
        if (Visited[Graphs[NextY][NextX] - 'A'])
            continue;

        // 이제 DFS
        Visited[Graphs[NextY][NextX] - 'A'] = true;
        DFS(Graphs, Visited, R, C, NextY, NextX, Move);
        Visited[Graphs[NextY][NextX] - 'A'] = false;
    }


}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<bool> Visited(26, false);
    vector<vector<char>> Graphs;
    int R, C;
    cin >> R >> C;

    Graphs.resize(R, vector<char>(C, '0'));

    for (int i = 0; i < R; ++i)
    {
        string Input;
        cin >> Input;
        
        for (int j = 0; j < C; ++j)
        {
            Graphs[i][j] = Input[j];
        }
    }

    Visited[Graphs[0][0] - 'A'] = true;
    DFS(Graphs, Visited, R, C, 0, 0, 0);

    cout << Answer;


    return 0;
}
