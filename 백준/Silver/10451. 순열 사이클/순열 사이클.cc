#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void DFS(vector<int>& Graphs, vector<bool>& Visited, int Now)
{
    Visited[Now] = true;

    if (false == Visited[Graphs[Now]])
        DFS(Graphs, Visited, Graphs[Now]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int N;
        int Count = 0;

        cin >> N;

        vector<int> Graphs(N + 1);
        vector<bool> Visited(N + 1, false);

        for (int j = 1; j <= N; ++j)
        {
            int Input;
            cin >> Input;

            Graphs[j] = Input;
        }

        for (int j = 1; j <= N; ++j)
        {
            if (false == Visited[j])
            {
                ++Count;
                DFS(Graphs, Visited, j);
            }
        }

        cout << Count << '\n';
    }

    return 0;
}
