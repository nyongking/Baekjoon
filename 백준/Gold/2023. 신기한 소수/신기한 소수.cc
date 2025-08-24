#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool IsPrime(int x)
{
    if (x < 2) return false;
    if (x == 2) return true;
    if (0 == x % 2) return false;

    for (int i = 3; i * i <= x; i += 2)
    {
        if (0 == x % i)
            return false;
    }
    return true;
}

int Numbers[4] = { 1, 3, 7, 9 };
void dfs(int number, int digit, int targetdigit)
{
    if (digit == targetdigit)
        cout << number << '\n';

    for (int i = 0; i < 4; ++i)
    {
        int Next = number * 10 + Numbers[i];

        if (false == IsPrime(Next))
            continue;
        
        else
            dfs(Next, digit + 1, targetdigit);
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int start[4] = { 2, 3, 5, 7 };

    for (int i = 0; i < 4; ++i)
    {
        int number = start[i];

        if (N == 1)
            cout << number << '\n';
        else
            dfs(number, 1, N);
    }

    return 0;
}