#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*
                    00*00
                    0*0*0
                    *****
                 00*00 00*00
                 0*0*0 0*0*0
                 ***** *****
*/

vector<vector<char>> Stars;

void PrintStar(int N, int i, int j)
{
    if (3 == N)
    {
        Stars[i][j] = '*';
        Stars[i + 1][j - 1] = Stars[i + 1][j + 1] = '*';
        Stars[i + 2][j] = Stars[i + 2][j + 1] = Stars[i + 2][j + 2] = Stars[i + 2][j - 1] = Stars[i + 2][j - 2] = '*';
    }
    else
    {
        PrintStar(N / 2, i, j);
        PrintStar(N / 2, i + N / 2, j - N / 2);
        PrintStar(N / 2, i + N / 2, j + N / 2);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int Column = (N / 3) * 5 + (N / 3 - 1);
    
    Stars.resize(N, vector<char>(Column, ' '));

    PrintStar(N, 0, Column / 2);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < Column; ++j)
        {
            cout << Stars[i][j];
        }
        cout << '\n';
    }

    return 0;

}