#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> Fibonaccis;

int GetFibonacciNum(int N)
{
    if (N == 0)
        Fibonaccis[0] = 0;
    else if (N == 1)
        Fibonaccis[1] = 1;
    else if (0 == Fibonaccis[N])
    {
        Fibonaccis[N] = GetFibonacciNum(N - 1) + GetFibonacciNum(N - 2);

    }
   

    return Fibonaccis[N];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;

    cin >> N;

    Fibonaccis.resize(N + 1, 0);

    cout << GetFibonacciNum(N);

    return 0;
}