#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

list<int> CanUse;

int CalDigit(int N)
{
    int Answer = 0;
    int Cal = N;

    if (0 == N)
        return 1;

    while (0 != Cal)
    {
        Cal /= 10;
        ++Answer;
    }

    return Answer;
}

void CalDigitNumbers(int Digit, list<int>& OutNumbers, int NowDigit, int NowNumber)
{
    if (Digit == NowDigit)
    {
        OutNumbers.push_back(NowNumber);
        return;
    }

    for (auto& UseNumber : CanUse)
    {
        int NextNumber = NowNumber * 10 + UseNumber;
        // 0일 때를 위해,..
        CalDigitNumbers(Digit, OutNumbers, NowDigit + 1, NextNumber);
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<int> UseNumbers;
    vector<bool> Broken(10, false);
    int N, M;
    int Start = 100;
    int Answer = 0;

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int Input;
        cin >> Input;

        Broken[Input] = true;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (Broken[i])
            continue;

        CanUse.push_back(i);
    }
    // 1. 시작번호부터에서 판단
    if (Start <= N)
        Answer = N - Start;
    else
        Answer = Start - N;

    // 2. 개수 판단 + 고장난 버튼 수 판단(0, 10)
    if (Answer <= 3 || 10 == M)
    {
        cout << Answer;
        return 0;
    }

    if (0 == M)
    {
        cout << CalDigit(N);
        return 0;
    }

    // 3. 자릿수
    int Digit = CalDigit(N);

    // 4. 사용가능 숫자
    for (int CalDigit = Digit - 1; CalDigit <= Digit + 1; ++CalDigit)
    {
        if (0 >= CalDigit)
            continue;

        CalDigitNumbers(CalDigit, UseNumbers, 0, 0);
    }

    // 5. Answer 판단.
    for (auto UseNumber : UseNumbers)
    {
        int Count = CalDigit(UseNumber);

        if (UseNumber <= N)
            Count += (N - UseNumber);
        else
            Count += (UseNumber - N);

        if (Answer > Count)
            Answer = Count;
    }

    cout << Answer;


    return 0;
}
