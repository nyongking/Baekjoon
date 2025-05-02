#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Dest, Cost
    vector<vector<pair<int, int>>> Graph;
    vector<int> Costs;

    // Cost, Dest
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

    int Start;
    int V, E;
    
    cin >> V >> E;
    cin >> Start;
    Graph.resize(V + 1, vector<pair<int, int>>());
    Costs.resize(V + 1, INT32_MAX);
       

    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        Graph[u].push_back(make_pair(v, w));
    }

    PQ.push(make_pair(0, Start));
    Costs[Start] = 0;

    while (false == PQ.empty())
    {
        pair<int, int> Top = PQ.top();
        PQ.pop();

        if (Top.first > Costs[Top.second])
            continue;

        for (int i = 0; i < Graph[Top.second].size(); ++i)
        {
            pair<int, int> Next = Graph[Top.second][i];

            if (Next.second + Top.first < Costs[Next.first])
            {
                PQ.push(make_pair(Next.second + Top.first, Next.first));
                Costs[Next.first] = Next.second + Top.first;
            }
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        if (INT32_MAX == Costs[i])
            cout << "INF\n";
        else
            cout << Costs[i] << '\n';
    }



    return 0;
}
