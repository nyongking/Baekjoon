#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Point
{
    Point(int64_t _Cost, int64_t _Now, int64_t _Index) : Cost(_Cost), Now(_Now), Index(_Index) {}
    int64_t Cost;
    int64_t Now;
    int64_t Index;
};

struct Compare
{
    bool operator()(const Point& Src, const Point& Dest)
    {
        return Src.Cost > Dest.Cost;
    }
};
/*
    1 2 0
    6 7 1
    2 6 2
    3 4 3
    5 6 4
    sdf 5
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Cost, Dest
    priority_queue<Point, vector<Point>, Compare> PQ;
    vector<int64_t> Costs;
    vector<vector<pair<int64_t, int64_t>>> CrossRoads;
    int64_t N, M;
    int64_t Signal = 0;

    cin >> N >> M;
    CrossRoads.resize(N + 1, vector<pair<int64_t, int64_t>>());
    Costs.resize(N + 1, INT64_MAX);

    for (int i = 0; i < M; ++i)
    {
        int64_t Start, End;
        cin >> Start >> End;

        CrossRoads[Start].push_back(make_pair(i, End));
        CrossRoads[End].push_back(make_pair(i, Start));
    }

    PQ.push(Point(0, 1, -1));
    Costs[1] = 0;


    while (false == PQ.empty())
    {
        Point Top = PQ.top();
        PQ.pop();

        if (Top.Cost > Costs[Top.Now])
            continue;

        for (int i = 0; i < CrossRoads[Top.Now].size(); ++i)
        {
            pair<int64_t, int64_t> Next = CrossRoads[Top.Now][i];

            int64_t NextCost = 0;

            if (Next.first > Top.Index)
                NextCost = Next.first - Top.Index;
            else
                NextCost = M - (Top.Index - Next.first);
            
            if (Top.Cost + NextCost < Costs[Next.second])
            {
                PQ.push(Point(Top.Cost + NextCost, Next.second, Next.first));
                Costs[Next.second] = Top.Cost + NextCost;
            }
        }
    }

    cout << Costs[N];

    return 0;
}
