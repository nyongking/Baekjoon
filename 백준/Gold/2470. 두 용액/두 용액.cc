#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

/*

2개를 뽑아서 가장 0에 가깝게 만들어라.
N = 100000, -> 최대 5000C3



-97, -6, -2, 6 98 -> -97, -2, 98

-24 -6 -3 -2 61 98 100 -> -6 -3 -2



*/


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> Solutions;
    int N;
    int Answer1, Answer2;
    int First, Second;
    int Sum = INT32_MAX;

    cin >> N;

    First = 0; Second = N - 1;
    Answer1 = 0; Answer2 = N - 1;
    Solutions.resize(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Solutions[i];
    }

    sort(Solutions.begin(), Solutions.end());

    while (First < Second)
    {
        int NowSum = Solutions[First] + Solutions[Second];

        // 합, 인덱스 갱신
        if (abs(Sum) > abs(NowSum))
        {
            Sum = NowSum;
            Answer1 = First;
            Answer2 = Second;
        }

        // 0이면 break;
        if (0 == NowSum)
            break;

        // 합이 0보다 크다 -> Second를 줄임.
        if (0 < NowSum)
            --Second;
        if (0 > NowSum)
            ++First;

    }
    
    cout << Solutions[Answer1] << ' ' << Solutions[Answer2];
    

    return 0;
}
