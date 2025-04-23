#include <iostream>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M = 0;
    int Digit = 0, Origin;
    cin >> N;

    Origin = N;
    while (0 != Origin)
    {
        ++Digit;
        Origin /= 10;
    }
    
    for (int i = N - Digit * 9; i < N; ++i)
    {
        int Sum = 0;
        Origin = i;
        while (0 != Origin)
        {
            Sum += Origin % 10;
            Origin /= 10;
        }

        if (i + Sum == N)
        {
            M = i;
            break;
        }
    }
    
    cout << M;


    return 0;
}
