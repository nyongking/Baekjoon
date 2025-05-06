#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

/*

3개를 뽑아서 가장 0에 가깝게 만들어라.
N = 5000, -> 최대 5000C3

-97, -6, -2, 6 98 -> -97, -2, 98

-24 -6 -3 -2 61 98 100 -> -6 -3 -2

Start End + Mid



*/


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> Solutions;
    int N;
    int Start, Mid, End;
    int Answer1, Answer2, Answer3;
    int64_t Sum = INT64_MAX;

    cin >> N;
    Solutions.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> Solutions[i];

    sort(Solutions.begin(), Solutions.end());

    // Start Index를 고정, 새로운 Start Index, End Index 설정
    for (int i = 0; i < N - 2; ++i)
    {
        Start = i;
        Mid = i + 1;
        End = N - 1;

        while (Mid < End)
        {
            int64_t NowSum = (int64_t)Solutions[Start] + Solutions[Mid] + Solutions[End];

            // 합, 인덱스 갱신
            if (abs(NowSum) < abs(Sum))
            {
                Sum = NowSum;
                Answer1 = Start;
                Answer2 = Mid;
                Answer3 = End;
            }

            // 합이 0일 경우 끝.
            if (0 == NowSum)
            {
                cout << Solutions[Answer1] << ' ' << Solutions[Answer2] << ' ' << Solutions[Answer3];
                return 0;
            }

            // 합이 0보다 클 경우 -> End를 줄임
            if (0 < NowSum)
                --End;
            else
                ++Mid;
        }
    }

    cout << Solutions[Answer1] << ' ' << Solutions[Answer2] << ' ' << Solutions[Answer3];


    return 0;
}
