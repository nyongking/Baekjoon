#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

bool Visited[100'001] = {};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    // 시간, 현재 위치
    list<pair<int, int>> Queue;
    
    Queue.push_back(make_pair(0, N));
    Visited[N] = true;

    while (false == Queue.empty())
    {
        pair<int, int> Top = Queue.front();
        
        int Now = Top.second;

        if (K == Now)
        {
            cout << Top.first;
            return 0;
        }


        int Next[3] = { Now - 1, Now + 1, 2 * Now };

        for (int i = 0; i < 3; ++i)
        {
            // 범위 판단
            if (0 > Next[i] || 100'000 < Next[i])
                continue;

            // Visited 판단
            if (Visited[Next[i]])
                continue;

            // push Queue
            Queue.push_back(make_pair(Top.first + 1, Next[i]));
            Visited[Next[i]] = true;
        }

        Queue.pop_front();

    }

    return 0;
}
