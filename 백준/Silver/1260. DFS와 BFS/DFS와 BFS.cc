#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void DFS(vector<bool>& Visited, vector<vector<int>>& Graph, int Now)
{
    Visited[Now] = true;
    cout << Now << ' ';

    for (auto& Dest : Graph[Now])
    {
        if (false == Visited[Dest])
            DFS(Visited, Graph, Dest);
    }
}

void BFS(int Count, vector<vector<int>>& Graph, int Start)
{
    vector<int> Visited(Count + 1, -1);
    list<int> Queue;
    Queue.push_back(Start);

    int Now = Start;
    Visited[Now] = 0;

    while (false == Queue.empty())
    {
        Now = Queue.front();
        cout << Now << ' ';

        for (auto& Dest : Graph[Now])
        {
            if (-1 == Visited[Dest])
            {
                Queue.push_back(Dest);
                Visited[Dest] = Now;
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

    int N, M, V;
    cin >> N >> M >> V;

    vector<bool> Visited(N + 1, false);
    vector<vector<int>> Graph(N + 1, vector<int>());

    for (int i = 0; i < M; ++i)
    {
        int Start, Next;
        cin >> Start >> Next;

        Graph[Start].push_back(Next);
        Graph[Next].push_back(Start);
    }

    for (auto& Line : Graph)
    {
        sort(Line.begin(), Line.end());
    }

    DFS(Visited, Graph, V);
    cout << '\n';
    BFS(N, Graph, V);
    
    return 0;
}
