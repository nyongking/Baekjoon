#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*

Sum[i][j] = min(Sum[i][k] + Sum[k][j]) + i~j까지의 Data


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
        vector<vector<int64_t>> Mins;
        vector<int> Datas;
        int N;


        cin >> N;
        Datas.resize(N, 0);
        Mins.resize(N, vector<int64_t>(N, 0));

        for (int i = 0; i < N; ++i)
        {
            cin >> Datas[i];
            //Mins[i][i] = Datas[i];
        }

        for (int Index = 0; Index < N - 1; ++Index)
        {
            Mins[Index][Index + 1] = Datas[Index] + Datas[Index + 1];
        }

        for (int i = 2; i <= N; ++i)
        {
            for (int Index = 0; Index < N; ++Index)
            {
                int EndIndex = Index + i;
                if (N <= EndIndex)
                    break;

                int Sum = 0;
                for (int j = Index; j <= EndIndex; ++j)
                    Sum += Datas[j];

                // 최소값 판정
                int64_t Min = INT64_MAX;
                for (int MidIndex = Index; MidIndex < EndIndex; ++MidIndex)
                {
                    Min = min(Mins[Index][MidIndex] + Mins[MidIndex + 1][EndIndex], Min);
                }

                Mins[Index][EndIndex] = Sum + Min;
            }
        }
        
        cout << Mins[0][N - 1] << '\n';

    }



    return 0;

}