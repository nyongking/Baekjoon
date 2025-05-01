#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int GetOneToNum(int Num)
{
    if (1 == Num % 2)
    {
        return (2 + Num) * (Num / 2) + 1;
    }
    else
    {
        return (1 + Num) * (Num / 2);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 2개 -> 3, 5, 7..
    // 3개 -> 6, 9, 12
    // 4개 -> 10, 14, 18..
    // 5개 -> 15, 20, 25 

    int Answer = 0;
    int N;
    cin >> N;

    int SumCount = 1;
    while (true)
    {
        int Sum = GetOneToNum(SumCount);

        if (Sum > N)
            break;

        if (0 == (N - Sum) % SumCount)
            ++Answer;

        ++SumCount;
    }


    cout << Answer;

    return 0;
}
