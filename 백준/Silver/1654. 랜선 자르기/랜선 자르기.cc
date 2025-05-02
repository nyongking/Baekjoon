#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

int64_t CountRope(vector<int>& Ropes, int64_t Length)
{
    int64_t Count = 0;
    for (int i = 0; i < Ropes.size(); ++i)
    {
        int Rope = Ropes[i];

        Count = Count + (Rope / Length);
    }

    return Count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // K개 갖고 있고, N개를 만들거야.

    // 최대 값 -> K개의 줄 중, 제일 작은 값
    // 최소 값 -> 1부터 시작

    vector<int> Ropes;
    int K, N;
    int Maximum = 0;
    int Minimum = 0;
    cin >> K >> N;

    Ropes.resize(K, 0);

    for (int i = 0; i < K; ++i)
    {
        int Input;
        cin >> Input;

        Ropes[i] = Input;
        if (Maximum < Input)
            Maximum = Input;

    }

    while (Minimum < Maximum)
    {
        int64_t Med = ((int64_t)Minimum + (int64_t)Maximum) / 2 + 1;
        int64_t Count = CountRope(Ropes, Med);

        // 개수 조건 충족
        if (N <= Count)
        {
            Minimum = Med;
        }
        else
        {
            Maximum = Med - 1;
        }
    }

    cout << Minimum;



    return 0;
}
