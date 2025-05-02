#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

/*
    대각선 이동 : {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // 2, 0, 0, -2
    대각선 이동만으로 갈 수 있는 곳 -> X + Y의 합이 짝수
    홀수인 경우 ->  X + Y - 1만큼 대각선, 1만큼 직선 
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int X, Y;
    int W, S;
    int64_t Answer = INT64_MAX;

    cin >> X >> Y;
    cin >> W >> S;

    // 답은 총 3개 중 1개
    // 1. 무조건 직각으로 움직이기
    // 2. 최대 대각선으로 (1, 1) 움직이고, 직각으로 움직이고
    // 3. 거의(전부) 대각선으로 움직이기
    

    int64_t Time = 0;
     // 1번 경우
    {
        Time = (int64_t)(X + Y) * W;

        if (Answer > Time)
            Answer = Time;
    }
    // 2번 경우
    {
        int Diagonal = min(X, Y);
        int Straight = X - Diagonal + Y - Diagonal;
        Time = (int64_t)Diagonal * S + (int64_t)Straight * W;

        if (Answer > Time)
            Answer = Time;
    }
    // 3번 경우
    {
        if (0 == (X + Y) % 2)
        {
            int Diagonal = max(X, Y);
            Time = (int64_t)Diagonal * S;
        }
        else
        {
            int Diagonal = max(X, Y) - 1;
            Time = (int64_t)Diagonal * S + W;
        }
        
        if (Answer > Time)
            Answer = Time;
    }
    
    cout << Answer;

    return 0;
}
