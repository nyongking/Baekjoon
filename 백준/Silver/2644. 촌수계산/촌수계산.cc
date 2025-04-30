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
    int X, Y;

    cin >> N;
    cin >> X >> Y;
    cin >> M;

    vector<vector<int>> Graphs(N + 1, vector<int>());
    vector<bool> Visited(N + 1, false);
    list<pair<int, int>> Queue;

    for (int i = 0; i < M; ++i)
    {
        int Start, End;
        cin >> Start >> End;

        Graphs[Start].push_back(End);
        Graphs[End].push_back(Start);
    }
    
    // BFS
    Queue.push_back(make_pair(0, X));
    Visited[X] = true;

    while (false == Queue.empty())
    {
        pair<int, int> Top = Queue.front();

        for (int Dest : Graphs[Top.second])
        {
            // Dest 체크
            if (Y == Dest)
            {
                cout << Top.first + 1;
                return 0;
            }

            if (false == Visited[Dest])
            {
                Queue.push_back(make_pair(Top.first + 1, Dest));
                Visited[Dest] = true;
            }
        }

        Queue.pop_front();
    }    

    cout << -1;


    return 0;
}
