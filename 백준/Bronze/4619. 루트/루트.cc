#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A;
    int B, N;

    while (true)
    {
        cin >> B >> N;

        if (0 == B && 0 == N)
            break;

        // A^N이 B에 가까운 A찾기
        // N = 1이면, A = B일때 가장 가까운 값
        if (1 == N)
        {
            A = B;
        }

        else
        {
            for (int i = 1; i <= 1'000'000; ++i)
            {
                int Now = 1;

                for (int j = 1; j <= N; ++j)
                    Now *= i;

                if (B <= Now)
                {
                    int Prev = 1;
                    for (int j = 1; j <= N; ++j)
                        Prev *= (i - 1);

                    //
                    if (Now - B < B - Prev)
                        A = i;
                    else
                        A = i - 1;

                    break;
                }
            }
        }

        cout << A << endl;

    }

    return 0;
}
