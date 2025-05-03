#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;


// W, H
/*
    f1 = 1
    (WH)
    f2 = 2
    (W WH H / W HW H)
    f3 = 5
    (W W WHH H, W W HWH H, W H WHW H, W H WWH H, W H WWH H)
    
    처음은 W 마지막은 H,
    -> N-1개의 W,H로 조합
    -> 두번째 문자가 -> W = N-2개의 W, N-1개의 H로 조합 + H = N-1개의 W, N-2개의 H로 조합

    N = 4 -> WWW HHH 조합
    1. H (WWW, HH 조합) -> 무조건 첫번째는 W가 나와야 함 -> WW, HH 조합
    2. W (WW, HHH 조합) -> 2-1) W가 나올 때 + 2-2) H가 나올 때 .. 
*/

vector<vector<int64_t>> Cases;

int64_t GetCombination(int WCount, int HCount)
{
    if (-1 == Cases[WCount][HCount])
    {
        int64_t Result = 0;
        if (0 == WCount && 0 == HCount)
        {
            Result = Cases[WCount][HCount] = 1;
        }
        else if (0 == WCount)
        {
            Result = Cases[WCount][HCount] = 1;
        }
        else if (0 == HCount && 1 == WCount)
        {
            Result = Cases[WCount][HCount] = 1;
        }
        else if (0 == HCount)
        {
            Result = Cases[WCount][HCount] = 0;
        }
        else if (HCount < WCount)
        {
            Result = Cases[WCount][HCount] = GetCombination(WCount - 1, HCount);
        }
        else if (HCount >= WCount)
        {
            Result = Cases[WCount][HCount] = GetCombination(WCount - 1, HCount) + GetCombination(WCount, HCount - 1);
        }

        return Result;
    }
    else
        return Cases[WCount][HCount];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Cases.resize(31, vector<int64_t>(31, -1));

    while (true)
    {
        int N;
        cin >> N;

        if (0 == N)
            break;

        cout << GetCombination(N - 1, N - 1) << '\n';

    }



    return 0;
}
