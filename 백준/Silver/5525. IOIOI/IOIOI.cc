#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    string S;

    cin >> N >> M;
    cin >> S;

    int Offset = 0, Answer = 0;
    int IOICount = 0;

    // IOI 개수를 알아야 한다.
    // I -> O -> I 진행
    // I -> I -> O
    // I -> O -> O
    // O -> +1 Offset
    while (Offset < M)
    {
        if ('I' == S[Offset])
        {
            // 조건 충족
            if (Offset + 2 < M && 'O' == S[Offset + 1] && 'I' == S[Offset + 2])
            {
                ++IOICount;
                Offset += 2;
            }
            else
            {
                if (N <= IOICount)
                {
                    Answer = Answer + IOICount - N + 1;
                }
                ++Offset;
                IOICount = 0;
            }
        }
        else
        {
            ++Offset;
        }
    }

    cout << Answer;

    return 0;
}
