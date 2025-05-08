#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;


/*
    // 남은 기간
    // 사용 계획

    10 5 4      -> 10 125 124
    10 100 101     10 100 101

    1. Plan을 정렬
    2. 정렬된 Plan에 따라 사용할건데 
        2.1 Plan보다 더 작은 기간의 다른 Expire 존재 -> 기간 늘림
        @ 2.2 그 Plan보다 Expire가 작음 -> 기간 늘림, 
        @ 일단 기간을 다 늘리고 시작

    기간을 다 늘리고 나서 -> 2.1을 판단
    2.1 판단 방법
    - 정렬된 Plan의 Expire부터 비교 -> 기간을 늘린다.
*/

struct Compare
{
    bool operator()(pair<int, int> Src, pair<int, int> Dest)
    {
        if (Src.first == Dest.first)
        {
            return Src.second < Dest.second;
        }
        return Src.first < Dest.first;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> Gifts;
    vector<int> Plans; // 사용 계획
    vector<int> Expires; // 남은 기간
    int N;
    int64_t Answer = 0;

    cin >> N;
    Plans.resize(N, 0);
    Expires.resize(N, 0);
    Gifts.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> Expires[i];
    
    for (int i = 0; i < N; ++i)
        cin >> Plans[i];

    // 남은 기간 늘리기
    for (int i = 0; i < N; ++i)
    {
        if (Expires[i] < Plans[i])
        {
            int Count = (Plans[i] - Expires[i]) / 30;

            if (0 != (Plans[i] - Expires[i]) % 30)
                ++Count;

            Expires[i] = Expires[i] + 30 * Count;

            Answer += (int64_t)Count;
        }

        Gifts[i] = make_pair(Plans[i], Expires[i]);
    }

    // 정돈
    sort(Gifts.begin(), Gifts.end(), Compare());
    
    // 기프티콘 비교
    int PrevMaxExpire = 0;
    bool Extend = false;

    for (int i = 0; i < N - 1; )
    {
        // 계획이 더 길면서, 유효기간이 더 짧아 -> 늘린다.
        if (Gifts[i].first < Gifts[i + 1].first && (Gifts[i].second > Gifts[i + 1].second || PrevMaxExpire > Gifts[i + 1].second))
        {
            int ExpireDate = max(Gifts[i].second, PrevMaxExpire);

            int NextPlanDate = Gifts[i + 1].first;

            // 다음 기프티콘을 보면서 비교, 기간 늘리기
            while (i < N - 1 && Gifts[i + 1].first == NextPlanDate && (Gifts[i + 1].second < ExpireDate))
            {
                int Count = (ExpireDate - Gifts[i + 1].second) / 30;
                if (0 != (ExpireDate - Gifts[i + 1].second) % 30)
                    ++Count;

                Gifts[i + 1].second = Gifts[i + 1].second + 30 * Count;

                PrevMaxExpire = max(Gifts[i + 1].second, PrevMaxExpire);

                Answer += (int64_t)Count;
                ++i;

                Extend = true;
            }

            Extend = false;
        }

        // 기간 늘리고 난 뒤, 계획은 같은데 유효기간이 앞에 것이 더 길다면?
        else
        {
            ++i;
        }

    }

    cout << Answer;


    return 0;
}
