#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

/*

    5 2 4 1 3
        |
    1 2 3 4 5
    [5] 1 2 3 4
    [5] 2 3 4 [1]
    [5] 2 4 [1] [3]

    1 -> 0
    2 -> 최대 1 (2, 1)
    3 -> 최대 2
    4 -> 최대 3
    5 -> 최대 4
    ..

    3 2 1 -> 2
    1 3 2 -> 1

    4 3 2 1 -> 3
    3 2 4 1 -> 2


    5 4 3 2 1
    5
    4 3 5 1 2 -> 3
    3 1 4 2 5 -> 2
    2 4 1 5 3 -> 3
    5 4 3 1 2 -> 3? 2?

    Answer = N - 1 - max(증가의 연속된 개수)
        

*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> Rows;
    int MaxContinue = 0;
    int N;

    cin >> N;
    Rows.resize(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        int Input;
        cin >> Input;

        Rows[Input] = i;
    }

    int Continue = 0;
    int Now = 0;
    Now = Rows[1];

    for (int i = 2; i <= N; ++i)
    {
        int Next = Rows[i];
        if (Next > Now)
            ++Continue;
        else
        {
            MaxContinue = max(MaxContinue, Continue);
            Continue = 0;
        }
        Now = Next;
    }

    MaxContinue = max(MaxContinue, Continue);

    cout << N - 1 - MaxContinue;

    return 0;
}
