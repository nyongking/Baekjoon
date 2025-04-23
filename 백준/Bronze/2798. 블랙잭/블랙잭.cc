#include <iostream>
using namespace std;

#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    int Card[100] = {};
    int Answer = 0;

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> Card[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            for (int k = j + 1; k < N; ++k)
            {
                int Sum = Card[i] + Card[j] + Card[k];

                if (Sum == M)
                {
                    cout << Sum << '\n';
                    return 0;
                }

                else if (Sum < M && Answer < Sum)
                    Answer = Sum;

            }
        }
    }

    cout << Answer << '\n';

    return 0;
}
