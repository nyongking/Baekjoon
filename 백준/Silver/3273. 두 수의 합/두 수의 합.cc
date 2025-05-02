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

    int Count = 0;
    int Target;
    int N;
    cin >> N;

    vector<bool> Numbers(100'0001, false);
    list<int> NumList;

    for (int i = 0; i < N; ++i)
    {
        int Input;
        cin >> Input;

        Numbers[Input] = true;
        NumList.push_back(Input);
    }
    
    NumList.sort();

    cin >> Target;

    for (auto Number : NumList)
    {
        int Dest = Target - Number;
        
        if (0 >= Dest)
            continue;

        if (Numbers[Dest])
            ++Count;
    }

    cout << Count / 2;
    


    return 0;
}
