#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void BFS(vector<vector<int>>& Graphs, vector<bool>& Visited, int Start)
{
    list<int> Queue;

    Queue.push_back(Start);
    Visited[Start] = true;

    while (false == Queue.empty())
    {
        int Top = Queue.front();

        for (int Next : Graphs[Top])
        {
            if (false == Visited[Next])
            {
                Visited[Next] = true;
                Queue.push_back(Next);
            }
        }

        Queue.pop_front();
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> Graphs(N + 1, vector<int>());
    vector<bool> Visited(N + 1, false);

    for (int i = 0; i < M; ++i)
    {
        int Start, End;
        cin >> Start >> End;

        Graphs[Start].push_back(End);
        Graphs[End].push_back(Start);
    }
    
    int Count = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (false == Visited[i])
        {
            BFS(Graphs, Visited, i);
            ++Count;
        }
    }

    cout << Count;

    return 0;
}
