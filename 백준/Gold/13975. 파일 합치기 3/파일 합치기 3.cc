#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int64_t Total = 0;
        int N;
        cin >> N;
        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> PQ;

        for (int i = 0; i < N; ++i)
        {
            int64_t FileSize;
            cin >> FileSize;

            PQ.push(FileSize);
        }

        while (1 < PQ.size())
        {
            int64_t First = PQ.top();
            PQ.pop();
            int64_t Second = PQ.top();
            PQ.pop();

            PQ.push(First + Second);
            Total += First + Second;
        }

        cout << Total << '\n';


    }


    return 0;
}
