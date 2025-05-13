#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;




int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int64_t>> Bit;
    int N;

    cin >> N;
    Bit.resize(N + 1, vector<int64_t>(2, 0));

    Bit[1][0] = 0;
    Bit[1][1] = 1;

    for (int i = 1; i < N; ++i)
    {
        Bit[i + 1][0] = Bit[i][1] + Bit[i][0];
        Bit[i + 1][1] = Bit[i][0];
    }

    cout << Bit[N][0] + Bit[N][1];

    return 0;

}