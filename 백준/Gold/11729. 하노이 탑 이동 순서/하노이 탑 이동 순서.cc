#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void Move(int Start, int Dest, list<pair<int, int>>& Ways)
{
    Ways.push_back(make_pair(Start, Dest));
}

int Hanoi(int N, int Start, int Dest, list<pair<int, int>>& Ways)
{
    int Result = 0;
    if (1 < N)
    {
        Result += Hanoi(N - 1, Start, 6 - (Start + Dest), Ways);
    }
    ++Result;
    Move(Start, Dest, Ways);
    if (1 < N)
    {
        Result += Hanoi(N - 1, 6 - (Start + Dest), Dest, Ways);
    }

    return Result;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // N개의 탑
    // N번째 블록을 1->3 하기 위해서
    // 1. N-1번째까지의 블록을 1->2로 옮겨야 함
    // 2. N-2번째까지의 블록을 2->1로 옮겨야 함
   
    // N-1번 블록을 1->2 하기 위해서 N-2번까지의 블록을 1->3 해야함.

    // Start Dest
    list<pair<int, int>> Ways;
    int N;
    cin >> N;

    cout << Hanoi(N, 1, 3, Ways) << '\n';

    for (auto& Way : Ways)
        cout << Way.first << ' ' << Way.second << '\n';

    return 0;
}
