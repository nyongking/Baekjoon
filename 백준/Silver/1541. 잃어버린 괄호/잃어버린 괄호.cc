#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

/*

    50 + 40 + 50 - 60 + 30 + 40 + 20 - 10 

*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    bool IsPlus = true;
    int NowNumber = 0;
    int AccNum = 0;
    int Answer = 0;

    string Formula;

    cin >> Formula;

    for (int i = 0; i < Formula.size(); ++i)
    {
        char Character = Formula[i];

        // 숫자일 경우
        if ('0' <= Character && '9' >= Character)
        {
            NowNumber = NowNumber * 10 + (Character - '0');
        }

        // 연산기호일 경우
        else
        {
            if ('-' == Character)
            {
                if (IsPlus)
                {
                    IsPlus = false;
                    Answer += NowNumber;
                    NowNumber = 0;
                }
                else
                {
                    AccNum -= NowNumber;
                    Answer += AccNum;
                    AccNum = 0;
                    NowNumber = 0;
                }
            }
            else
            {
                // 계속 더하기 중
                if (IsPlus)
                {
                    Answer += NowNumber;
                    NowNumber = 0;
                }
                // 빼기 중
                else
                {
                    AccNum -= NowNumber;
                    NowNumber = 0;
                }
            }
        }
    }

    if (IsPlus)
    {
        Answer += NowNumber;
        NowNumber = 0;
    }
    else
    {
        AccNum -= NowNumber;
        Answer += AccNum;
        AccNum = 0;
        NowNumber = 0;
    }

    cout << Answer;



    return 0;
}
