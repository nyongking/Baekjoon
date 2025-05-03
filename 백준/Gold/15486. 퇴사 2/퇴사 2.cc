#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    t일차,
    N일간의 일, P 수당
    
    f(t+N) = max(f(t+N), f(t) + P)

*/




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> MaxPay;
    vector<pair<int, int>> Works;
    int N;

    cin >> N;

    Works.resize(N);
    MaxPay.resize(N + 1, 0);

    for (int i = 0; i < N; ++i)
    {
        int Days, Money;

        cin >> Days >> Money;

        Works[i] = make_pair(Days, Money);
    }

    for (int i = 0; i < N; ++i)
    {
        int NextWorkDay = i + Works[i].first;

        // 범위 체크
        if (NextWorkDay <= N)
        {
            MaxPay[NextWorkDay] = max(MaxPay[NextWorkDay], MaxPay[i] + Works[i].second);
        }

        // 다음 날 반영
        int NextDay = i + 1;
        MaxPay[NextDay] = max(MaxPay[NextDay], MaxPay[i]);
    }


    cout << MaxPay[N];


    return 0;
}
