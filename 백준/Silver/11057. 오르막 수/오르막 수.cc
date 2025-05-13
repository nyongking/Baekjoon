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

    vector<vector<int>> EndNumbers;
    int N;
    int Answer = 0;

    cin >> N;
    EndNumbers.resize(N + 1, vector<int>(10, 0));

    for (int i = 0; i < 10; ++i)
        EndNumbers[1][i] = 1;

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = j; k < 10; ++k)
            {
                EndNumbers[i + 1][k] = (EndNumbers[i + 1][k] + EndNumbers[i][j]) % 10007;
            }
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        Answer = (Answer + EndNumbers[N][i]) % 10007;  
    }

    cout << Answer;

    return 0;

}