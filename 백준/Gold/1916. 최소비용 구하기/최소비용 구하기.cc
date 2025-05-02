#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Way
{
    Way(int _Next, int _Cost) : Next(_Next), Cost(_Cost) {}
    int Next;
    int Cost;
};

struct Compare
{
    bool operator()(const Way& Src, const Way& Dest)
    {
        return Src.Cost > Dest.Cost;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Cost, Dest
    vector<vector<pair<int, int>>> Graph;
    vector<int> Costs;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Dests;

    int N, M;
    int Start, End;
    cin >> N >> M;

    Graph.resize(N + 1, vector<pair<int, int>>());
    Costs.resize(N + 1, INT32_MAX);

    for (int i = 0; i < M; ++i)
    {
        int Src, Dest, Cost;
        cin >> Src >> Dest >> Cost;

        Graph[Src].push_back(make_pair(Cost, Dest));
    }

    cin >> Start >> End;

    Dests.push(make_pair(0, Start));

    while (false == Dests.empty())
    {
        pair<int, int> Top = Dests.top();
        Dests.pop();

        // Cost 비교
        if (Top.first > Costs[Top.second])
            continue;

        // Cost 갱신

        for (int i = 0; i < Graph[Top.second].size(); ++i)
        {
            // Cost 비교
            pair<int, int> Next = Graph[Top.second][i];

            if (Top.first + Next.first < Costs[Next.second])
            {
                Dests.push(make_pair(Top.first + Next.first, Next.second));
                Costs[Next.second] = Top.first + Next.first;
            }

        }

    }

    cout << Costs[End];


    return 0;
}
