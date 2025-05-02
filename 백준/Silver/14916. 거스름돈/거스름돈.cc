#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Answer = 0;
    int N;
    cin >> N;

    if (5 <= N)
    {
        int Count = N / 5;
        if (0 != (N - (Count * 5)) % 2)
        {
            Count = N / 5 - 1;
        }

        N = N - Count * 5;
        Answer = Answer + Count;
    }

    if (2 <= N)
    {
        int Count = N / 2;
        Answer += Count;
        N -= (Count * 2);
    }

    if (0 >= Answer || 0 != N)
    {
        Answer = -1;
    }

    cout << Answer;


    return 0;
}
