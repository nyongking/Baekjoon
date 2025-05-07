#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

/*

    N, I, M // 맵 크기, 그물 크기, 물고기 수

*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> FirstNumbers;
    vector<int> SecondNumbers;

    vector<int> A, B, C, D;
    int N;
    int64_t Answer = 0;

    cin >> N;
    A.resize(N);
    B.resize(N);
    C.resize(N);
    D.resize(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int Sum1 = A[i] + B[j];
            int Sum2 = C[i] + D[j];

            FirstNumbers.push_back(Sum1);
            SecondNumbers.push_back(Sum2);
        }
    }

    sort(FirstNumbers.begin(), FirstNumbers.end());
    sort(SecondNumbers.begin(), SecondNumbers.end(), greater<int>());

    int FirstIndex = 0;
    int SecondIndex = 0;

    while (FirstIndex < FirstNumbers.size() && SecondIndex < SecondNumbers.size())
    {
        int Sum = FirstNumbers[FirstIndex] + SecondNumbers[SecondIndex];

        if (0 == Sum)
        {
            int LeftCount = 1;
            int RightCount = 1;

            int FirstValue = FirstNumbers[FirstIndex];
            int SecondValue = SecondNumbers[SecondIndex];

            while (true)
            {
                ++FirstIndex;

                if (FirstIndex < FirstNumbers.size() && FirstValue == FirstNumbers[FirstIndex])
                    ++LeftCount;
                else
                    break;
            }
            
            while (true)
            {
                ++SecondIndex;

                if (SecondIndex < SecondNumbers.size() && SecondValue == SecondNumbers[SecondIndex])
                    ++RightCount;
                else
                    break;
            }

            Answer += (int64_t)LeftCount * RightCount;
        }

        else if (0 < Sum)
        {
            ++SecondIndex;
        }

        else if (0 > Sum)
        {
            ++FirstIndex;
        }
    }

    cout << Answer;


    return 0;
}
