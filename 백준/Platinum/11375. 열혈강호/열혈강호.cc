#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    BiMatch
*/
vector<vector<int>> WorkPairs;
vector<bool> Visit;
vector<int> Match;

bool dfs(int Now)
{
    if (Visit[Now])
        return false;
    Visit[Now] = true;

    for (int Target : WorkPairs[Now])
    {
        if (-1 == Match[Target] || dfs(Match[Target]))
        {
            Match[Target] = Now;
            return true;
        }

    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    WorkPairs.resize(N);

    for (int i = 0; i < N; ++i)
    {
        int Count;
        cin >> Count;

        for (int j = 0; j < Count; ++j)
        {
            int Work;
            cin >> Work;

            WorkPairs[i].push_back(Work - 1);
        }
    }

    Match.resize(M, -1);

    for (int i = 0; i < N; ++i)
    {
        Visit = vector<bool>(N, false);
        dfs(i);
    }

    int Answer = 0;
    for (int i = 0; i < M; ++i)
    {
        if (-1 != Match[i])
            ++Answer;
    }
    cout << Answer;

    return 0;
}