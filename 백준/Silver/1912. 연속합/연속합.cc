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

    int Answer = INT32_MIN;
    int Sum = 0;
    int N;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int Input;
        cin >> Input;

        int NowSum = Sum + Input;

        Sum = max(NowSum, Input);
        Answer = max(Answer, Sum);       
    }

    cout << Answer;

    return 0;

}