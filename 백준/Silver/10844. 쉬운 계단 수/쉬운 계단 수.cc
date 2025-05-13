#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


/*



*/



int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> Numbers;
    int N;
    int Answer = 0;

    cin >> N;

    Numbers.resize(N + 1, vector<int>(10, 0));

    for (int i = 1; i < 10; ++i)
        Numbers[1][i] = 1;

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (0 <= j - 1)
                Numbers[i + 1][j - 1] = (Numbers[i + 1][j - 1] + Numbers[i][j]) % 1'000'000'000;

            if (10 > j + 1)
                Numbers[i + 1][j + 1] = (Numbers[i + 1][j + 1] + Numbers[i][j]) % 1'000'000'000;
        }
    }



    for (int i = 0; i < 10; ++i)
    {
        Answer = (Answer + Numbers[N][i]) % 1'000'000'000;
    }

    cout << Answer;

    return 0;

}