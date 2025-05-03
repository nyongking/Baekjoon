#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    2개
    1 6 9 3 6 7
    1 3 6 6 7 9
    <1, 3> <6, 6, 7, 9>
    2 + 3 = 5

    1 3 6 7 9
     2 3 1 2
     2 3  3
     2 + 3

     3개
     2 3 1 2
     <2> <1> <2> = 5

     3개 -> 작은 숫자 3개, 제거 가능 숫자 2개
     1 3 6 7 9 11       = 5개의 빈칸 -> 작은 숫자 3개로 묶자.
      2 1 2         
     <1 3> <6 7 9 11>  
       2     1 2 2
     <1 3> <6 7> <9 11>

    5개 = 작은 숫자 5개, 제거 가능 숫자 4개
    20 3 14 6 7 8 18 10 12 15
    (3) (6 7 8) (10 12) (14 15 17) (20)
     0 1 1 0  0  2  1  2  0
   
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Destination, Index
    //priority_queue<pair<int, int>> Queue;
    vector<pair<int, int>> SortIntervals;
    vector<int> Intervals;

    vector<int> Sensor;
    int N, K;
    int Answer = 0;

    cin >> N >> K;

    Sensor.resize(N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> Sensor[i];
    }

    // 정렬 후 중복 제거
    sort(Sensor.begin(), Sensor.end());
    auto iter = unique(Sensor.begin(), Sensor.end());
    Sensor.erase(iter, Sensor.end());

    if (Sensor.size() <= K)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < Sensor.size() - 1; ++i)
    {
        int Interval = Sensor[i + 1] - Sensor[i];
        SortIntervals.push_back(make_pair(Interval, i));
        Intervals.push_back(Interval);
        Answer += Interval;
    }

    sort(SortIntervals.begin(), SortIntervals.end(), greater<pair<int, int>>());

    int Count = 0;
    for (auto& iter : SortIntervals)
    {
        if (K - 1 == Count)
            break;

        int Index = iter.second;

        Intervals[Index] = 0;
        Answer -= iter.first;
        ++Count;
    }
   
    cout << Answer;

    return 0;
}
