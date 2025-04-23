#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A = 0, B = 0, C = 0;
    int Time;

    cin >> Time;

    // A 입력횟수 계산
    if (300 <= Time)
    {
        A = Time / 300;
        Time -= A * 300;
    }

    // B 입력횟수 계산
    if (60 <= Time)
    {
        B = Time / 60;
        Time -= B * 60;
    }

    // C 입력횟수 계산
    if (10 <= Time)
    {
        C = Time / 10;
        Time -= C * 10;
    }

    // Time이 남아있을 경우 -> -1
    if (0 != Time)
    {
        cout << -1;
    }
    else
    {
        cout << A << ' ' << B << ' ' << C;
    }


    return 0;
}
