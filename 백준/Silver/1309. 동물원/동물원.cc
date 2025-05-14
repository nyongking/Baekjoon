#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*
0마리 배치 ->
1마리 배치

*/

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> Counts;
    int N;

    cin >> N;
    Counts.resize(N + 1, vector<int>(2, 0));

    Counts[1][0] = 1;
    Counts[1][1] = 2;

    for (int i = 2; i <= N; ++i)
    {
        Counts[i][0] = (Counts[i - 1][0] + Counts[i - 1][1]) % 9901;
        Counts[i][1] = (Counts[i - 1][0] * 2 + Counts[i - 1][1]) % 9901;
    }

    cout << (Counts[N][0] + Counts[N][1]) % 9901;

    return 0;

}