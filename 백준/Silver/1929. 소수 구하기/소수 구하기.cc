#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<bool> Prime(N + 1, true);
    Prime[0] = false;
    Prime[1] = false;

    for (int i = 2; i * i <= N; ++i)
    {
        if (false == Prime[i])
            continue;

        for (int j = i * 2; j <= N; j += i)
        {
            Prime[j] = false;
        }
    }

    for (int i = M; i <= N; ++i)
    {
        if (Prime[i])
            cout << i << '\n';
    }

    
    return 0;
}