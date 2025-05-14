#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*
1 = 1
2 = 2
3 = 3
4 = 1
5 = 2
6 = 3
7 = 4
8 = 2
9 = 1
10 = 2
11 = 3
12 = 3 @
13 = 2 *
14 = 3
15 = 4
16 = 1
17 = 2
18 = 2 *
19 = 3
...

*/

vector<int> Squares;

int GetMinSquareSum(vector<int>& MinSquares, int N)
{
    if (0 == N)
        return 0;

  /*  if (INT32_MAX == MinSquares[N])
    {
        int Number = 1;

        while (true)
        {
            int Square = Number * Number;

            if (0 == N - Square)
            {
                MinSquares[N] = 1;
                break;
            }
            if (0 > N - Square)
                break;

            MinSquares[N] = min(GetMinSquareSum(MinSquares, N - Square) + 1, MinSquares[N]);

            ++Number;
        }
    }*/
    MinSquares[0] = 0;

    for (int i = 1; i <= N; ++i)
    {
        int Number = 1;

        while (true)
        {
            int Square = Number * Number;

            if (0 == i - Square)
            {
                MinSquares[i] = 1;
                break;
            }
            if (0 > i - Square)
                break;

            MinSquares[i] = min(MinSquares[i - Square] + 1, MinSquares[i]);
            ++Number;
        }
    }


    return MinSquares[N];
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 400; ++i)
    {
        int Square = i * i;
        if (100'000 < Square)
            break;

        Squares.push_back(Square);
    }


    vector<int> MinSquareSums;
    int N;

    cin >> N;
    MinSquareSums.resize(N + 1, INT32_MAX);
    
    cout << GetMinSquareSum(MinSquareSums, N);


    return 0;

}