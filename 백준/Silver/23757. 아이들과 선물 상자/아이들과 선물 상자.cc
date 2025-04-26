#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int> Presents;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        int Input;
        cin >> Input;

        Presents.push(Input);
    }

    for (int i = 0; i < M; ++i)
    {
        int Want;
        cin >> Want;

        int Present = Presents.top();

        // 선물 개수 부족
        if (Present < Want)
        {
            cout << 0;
            return 0;
        }
        // 선물 충족
        else
        {
            Present -= Want;
            Presents.pop();

            if (0 < Present)
            {
                Presents.push(Present);
            }
        }
    }

    cout << 1;

    return 0;
}
