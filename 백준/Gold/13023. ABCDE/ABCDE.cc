#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

bool DFS(vector<vector<int>>& Graph, vector<bool>& Visited, vector<bool>& Search, int Now, int Count)
{
    Search[Now] = true;
    Visited[Now] = true;
    ++Count;

    if (5 == Count)
        return true;

    for (int Next : Graph[Now])
    {
        if (false == Visited[Next])
        {
            bool Result = DFS(Graph, Visited, Search, Next, Count);
            if (Result)
                return true;
        }
    }

    Visited[Now] = false;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> Graphs(N, vector<int>());
    vector<bool> Visited(N, false);
    vector<bool> Search(N, false);

    for (int i = 0; i < M; ++i)
    {
        int Start, End;
        cin >> Start >> End;

        Graphs[Start].push_back(End);
        Graphs[End].push_back(Start);
    }
    
    for (int i = 0; i < N; ++i)
    {
        //if (false == Search[i])
        {
            if (DFS(Graphs, Visited, Search, i, 0))
            {
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;


    return 0;
}
