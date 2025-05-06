#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    N(14)을 기준으로 앞쪽 움직이기, 뒤쪽 움직이기
    왼쪽 글자, 오른쪽 글자?

    알파벳 처리수는 고정.
    이동에서 최소를 구해야함, 최소의 이동은 어떻게?

    case는 2개.
    1) 왼쪽 글자부터 맨 오른쪽 글자까지 쭉 이어서 세는 경우.
        -> N - 1
    2) 왼쪽 글자에서 처리할 문자만 오른쪽으로, 그 뒤론 왼쪽으로
        근데 그걸 어떻게 판단하냐

    1. 'A'가 등장했을 경우 그 다음 'A'가 등장하지 않을 때까지 개수를 'A'의 개수 센다.
    2. 왼쪽 이동 Count + 오른쪽 이동 Count -> 최솟값 갱신

*/


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;

    cin >> T;
    
    for (int i = 0; i < T; ++i)
    {
        int Answer = 0;
        string Name;

        cin >> Name;

        // 알파벳 계산
        for (int i = 0; i < Name.size(); ++i)
        {
            if ('N' >= Name[i])
                Answer += Name[i] - 'A';
            else
                Answer += 'Z' - Name[i] + 1;
        }

        // 이동 값 계산
        int MinMove = Name.size() - 1;

        for (int i = 0; i < Name.size(); )
        {
            // A 알파벳이 나오면, 거기서부터 A의 길이를 잰다.
            if ('A' == Name[i])
            {
                // 오른쪽 이동 값
                int RightMove;
                if (0 == i)
                {
                    RightMove = 0;
                }
                else
                {
                    RightMove = i - 1;
                }

                int AsLength = 0;
                int LeftMove = 0;
                int LeftLength = i;

                // A의 문자열길이 계산.
                while (i < Name.size() && 'A' == Name[i])
                {
                    ++AsLength;
                    ++i;
                }

                // 왼쪽 이동 값
                // ****AAAAAAAA*** -> 
                // AAAAAAAA*** 8 3 11 -> 이동 3
                // *****AAA

                LeftMove = Name.size() - LeftLength - AsLength;
                
                    int MinDir = min(LeftMove, RightMove);
                MinMove = min(MinMove, MinDir + RightMove + LeftMove);
            }
            else
                ++i;
        }

        Answer += MinMove;

        cout << Answer << '\n';
        
    }


    return 0;
}
