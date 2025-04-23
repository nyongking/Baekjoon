#include <iostream>
#include <string>
#include <set>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    int Answer = N;

    for (int i = 0; i < N; ++i)
    {
        string Input;
        bool IsPrev[26] = {};
        char Prev = '\0';

        cin >> Input;

        for (int j = 0; j < Input.size(); ++j)
        {
            if (Prev != Input[j])
            {
                if (97 <= Input[j] && IsPrev[Input[j] - 97])
                {
                    // 이미 존재했던 경우
                    --Answer;
                    break;
                }

                // 알파벳 활성화
                if (97 <= Prev)
                {
                    IsPrev[Prev - 97] = true;
                }

                Prev = Input[j];
            }
            
        }

    }

    cout << Answer;

    return 0;
}
