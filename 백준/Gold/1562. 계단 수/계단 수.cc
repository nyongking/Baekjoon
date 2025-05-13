#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


/*

비트마스크,
[체크된 숫자][Digit 크기][현재 끝자리 숫자]
// 00000 00000

*/


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<vector<int>>> Numbers;
    int N;

    cin >> N;

    Numbers.resize(1 << 10, vector<vector<int>>(N + 1, vector<int>(10, 0)));

    // 9 이하일 경우, 계단 수 존재하지 않음
    if (9 >= N)
    {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < 10; ++i)
    {
        Numbers[1 << i][1][i] = 1;
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < (1 << 10); ++k)
            {
                if (0 < j)
                    //Numbers[k][i + 1][j] = (Numbers[k][i + 1][j] + (Numbers[k - (1 << j)][i][j - 1] + Numbers[k][i][j - 1]));/*) % 1'000'000'000) % 1'000'000'000;*/
                    Numbers[k | (1 << j)][i + 1][j] = (Numbers[k | (1 << j)][i + 1][j] + Numbers[k][i][j - 1]) % 1'000'000'000;


                if (9 > j)
                    //Numbers[k][i + 1][j] = (Numbers[k][i + 1][j] + (Numbers[k - (1 << j)][i][j + 1] + Numbers[k][i][j + 1]));/*) % 1'000'000'000) % 1'000'000'000;*/
                    Numbers[k | (1 << j)][i + 1][j] = (Numbers[k | (1 << j)][i + 1][j] + Numbers[k][i][j + 1]) % 1'000'000'000;

            }
        }
    }

    int Answer = 0;

    for (int i = 0; i < 10; ++i)
    {
        Answer = (Answer + Numbers[(1 << 10) - 1][N][i]) % 1'000'000'000;
    }


    cout << Answer;



    return 0;

}