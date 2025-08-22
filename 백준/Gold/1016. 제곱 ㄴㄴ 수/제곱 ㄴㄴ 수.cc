#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
제곱ㄴㄴ수

square -> 4, 9, 16, 25, 36, 49 -> 소수의 제곱만 거른다.
-> 4, 9, 25, 49, 121, 169..

1 ~ 10
->
1, 2, 3, 5, 6, 7, 10 -> 7



*/

vector<bool> Prime;

void MakePrime(unsigned long long MaxValue)
{
    unsigned long long Sqrtval = sqrt(MaxValue);

    Prime.resize(Sqrtval + 1, true);

    for (unsigned long long i = 2; i * i <= Sqrtval; ++i)
    {
        if (false == Prime[i])
            continue;

        for (unsigned long long j = i * 2; j <= Sqrtval; j += i)
            Prime[j] = false;
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned long long Min, Max;
    cin >> Min >> Max;
    
    MakePrime(Max);

    vector<bool> NonoSquare(Max - Min + 1, true);

    for (unsigned long long i = 2; i * i <= Max; ++i)
    {
        if (false == Prime[i])
            continue;

        unsigned long long Div = Min / (i * i);
        if (Min % (i * i))
            ++Div;

        while (Div * (i * i) <= Max)
        {
            NonoSquare[Div * i * i - Min] = false;
            ++Div;
        }
    }

    int Count = 0;
    for (size_t i = 0; i < NonoSquare.size(); ++i)
    {
        if (NonoSquare[i])
            ++Count;
    }

    cout << Count;
    
    return 0;
}