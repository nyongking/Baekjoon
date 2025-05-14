#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

/*

이동방식
연속 


*/


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // [현재 층][연속 이동 횟수]
    vector<vector<int>> Scores;
    int N;

    cin >> N;
    Scores.resize(N, vector<int>(2, 0));

    for (int i = 0; i < N; ++i)
    {
        int Input;
        cin >> Input;

        int NextStair = i + 1;
        if (NextStair < N)
        {
            Scores[NextStair][1] = max(Scores[NextStair][1], Scores[i][0] + Input);        
            //Scores[NextStair][0] = max(Scores[NextStair][0], Scores[i][1] + Input);        
        }

        NextStair = i + 2;
        if (NextStair < N)
        {
            Scores[NextStair][0] = max(Scores[NextStair][0], Scores[i][1] + Input);
            Scores[NextStair][0] = max(Scores[NextStair][0], Scores[i][0] + Input);
        }

        if (i == N - 1)
        {
            cout << max(Scores[i][0] + Input, Scores[i][1] + Input);
        }

    }



    return 0;

}