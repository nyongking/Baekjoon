#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

int Answer = INT32_MIN;

void Calc_By_Permutation(int PrevIndex, int Index, int Count, int Acc, vector<int>& Numbers, vector<bool>& Visited)
{
    Visited[Index] = true;
    ++Count;

    if (2 <= Count)
        Acc = Acc + abs(Numbers[PrevIndex] - Numbers[Index]);

    if (Count == Numbers.size())
    {
        Answer = max(Answer, Acc);
    }

    for (int i = 0; i < Numbers.size(); ++i)
    {
        if (Visited[i])
            continue;

        Calc_By_Permutation(Index, i, Count, Acc, Numbers, Visited);
    }

    Visited[Index] = false;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> Numbers;

    int N;
    cin >> N;


    for (int i = 0; i < N; ++i)
    {
        int Input;
        cin >> Input;

        Numbers.push_back(Input);
    }

    for (int i = 0; i < N; ++i)
    {
        vector<bool> Visited(N, false);

        Calc_By_Permutation(i, i, 0, 0, Numbers, Visited);
    }

    cout << Answer;

    return 0;
}
