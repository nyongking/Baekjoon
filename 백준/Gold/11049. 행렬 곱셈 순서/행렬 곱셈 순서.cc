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

    vector<vector<int>> Mins;
    vector<pair<int, int>>  Matrixs;
    int N;

    cin >> N;
    
    Mins.resize(N, vector<int>(N, 0ll));

    for (int i = 0; i < N; ++i)
    {
        int r, c;
        cin >> r >> c;

        Matrixs.push_back(make_pair(r, c));
    }

    for (int i = 0; i < N - 1; ++i)
    {
        Mins[i][i + 1] = Matrixs[i].first * Matrixs[i].second * Matrixs[i + 1].second;
    }

    for (int i = 2; i < N; ++i)
    {
        for (int Index = 0; Index < N; ++Index)
        {
            int EndIndex = Index + i;

            if (N <= EndIndex)
                break;

            int Minvalue = INT32_MAX;
            for (int MidIndex = Index; MidIndex < EndIndex; ++MidIndex)
            {
                Minvalue = min(Mins[Index][MidIndex] + Mins[MidIndex + 1][EndIndex] + Matrixs[Index].first * Matrixs[MidIndex].second * Matrixs[EndIndex].second, Minvalue);
            }

            Mins[Index][EndIndex] = Minvalue;
        }
    }

    cout << Mins[0][N - 1];
    return 0;

}